#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <vector>

struct Args {
  std::vector<unsigned int> i; /* index of points */
};

class LagrangeInterpParallel {
private:
  const unsigned int NUM_WORKERS = 5;
  double *basis; // lagrange basis functions
  size_t N;      // number of points
  double *x;
  double *y;

  void *basis_worker(void *args); /* worker thread to compute kth basis */

public:
  LagrangeInterpParallel(size_t, double *, double *);
  double *eval(double *, size_t);
};

LagrangeInterpParallel::LagrangeInterpParallel(size_t N, double *x, double *y) {
  this->N = N;
  this->x = (double *)malloc(N * sizeof(double));
  this->y = (double *)malloc(N * sizeof(double));
}

double *LagrangeInterpParallel::eval(double *x_test, size_t sz) {
  // compute the basis
  this->basis = (double *)malloc(N * sizeof(double));
  double *fx = (double *)malloc(N * sizeof(double));

  struct Args *worker_args =
      (struct Args *)malloc(NUM_WORKERS * sizeof(struct Args));

  for (int i = 0; i < N; ++i) {
    // distribute points amongst workers
    (worker_args[i % NUM_WORKERS].i).push_back(i);
  }

  return fx;
}

#ifdef DEBUG
void *driver(void *args) {
  size_t N;
  double *x, *y;

  printf("Enter number of points: ");
  std::cin >> N;
  x = (double *)malloc(N * sizeof(double));
  y = (double *)malloc(N * sizeof(double));
  for (int i = 0; i < N; ++i) {
    printf("x%d, y%d =", i, i);
    std::cin >> x[i] >> y[i];
  }
  LagrangeInterpParallel li(N, x, y);
  double *f = li.eval(x, N);
  return nullptr;
}

int main(int argc, char **argv) { driver(nullptr); }
#endif