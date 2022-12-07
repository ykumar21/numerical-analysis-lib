/*
 * Computes the derivative of a function
 * using richardson extrapolation
 */
#include <iostream>
#include <math.h>

#define DEBUG

class RSExtrapolator {
private:
  /* Enter function here */
  double f(double x) { return sin(x); };

  double phi(double x, double h) { return (f(x + h) - f(x - h)) / (2 * h); }

public:
  double solve(double, double, unsigned int);
};

double RSExtrapolator::solve(double x0, double h, unsigned int order) {
  unsigned int n, k; 
  k = (order - 2) / 2;
  n = k;
  double coef_tb[n][k];
  for (auto x = 0; x < k; ++x) {
    coef_tb[0][x] = phi(x0, h / pow(2, x));
      printf("D(%d,%d) = %f\n", 0, x, coef_tb[0][x]);
  }
  for (auto x = 1; x < k; ++x) {
    for (auto y = x; y < n; ++y) {
      double p = pow(4,x);
      //printf("c1 = %f, c2 = %f\n", p/(p-1), 1/(p-1));
      
      coef_tb[y][x] = coef_tb[y][x - 1] +  (coef_tb[y][x - 1] - coef_tb[y - 1][x - 1])/(p-1);
        printf("D(%d,%d) = %f\n", y, x, coef_tb[y][x]);
    }
  }
  printf("f'(%f) = %f\n", x0, coef_tb[n - 1][k - 1]);
  return coef_tb[n - 1][k - 1];
}

#ifdef DEBUG
int main(int argc, char **argv) {
  double x0 = 1.5;
  double h = 0.5;
  double order = 16;

  RSExtrapolator extrapolator;
  extrapolator.solve(x0, h, order);
}
#endif