#include <iostream>

class LagrangeInterp {
private:
  double *basis; // lagrange basis functions
  size_t N;      // number of points
  double *x;
  double *y;

public:
  LagrangeInterp(size_t, double *, double *);
  double *eval(double *, size_t);
};

LagrangeInterp::LagrangeInterp(size_t N, double *x, double *y) {
  this->N = N;
  this->x = (double *)malloc(N * sizeof(double));
  this->y = (double *)malloc(N * sizeof(double));
}

double *LagrangeInterp::eval(double *x_test, size_t sz) {
  // compute the basis
  this->basis = (double *)malloc(N * sizeof(double));
  double *fx = (double *)malloc(N * sizeof(double));

  for (int v = 0; v < sz; ++v) {
    double xc = x_test[v];
    double yc = 0;
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < N; ++j) {
        if (i == j)
          continue;
        basis[i] *= (xc - x[j]) / (x[i] - x[j]);
      }
      yc += y[i] * basis[i];
    }
    fx[v] = yc;
  }
  return fx;
}

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
  LagrangeInterp li(N, x, y);
  double *f = li.eval(x, N);
  return nullptr;
}

int main(int argc, char **argv) { driver(nullptr); }