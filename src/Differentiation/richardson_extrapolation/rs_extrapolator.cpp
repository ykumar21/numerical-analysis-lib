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
  double f(double x) { return sin(x)*cos(x)*tan(x*sin(cos(sin(x)))); };

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
  }
  for (auto x = 1; x < k; ++x) {
    for (auto y = x; y < n; ++y) {
      coef_tb[y][x] = coef_tb[y][x - 1] + coef_tb[y - 1][x - 1];
    }
  }
  printf("f'(%f) = %f\n", x0, coef_tb[n - 1][k - 1]);
  return coef_tb[n - 1][k - 1];
}

#ifdef DEBUG
int main(int argc, char **argv) {
  double x0 = 24.55;
  double h = 0.02;
  double order = 32;

  RSExtrapolator extrapolator;
  extrapolator.solve(x0, h, order);
}
#endif