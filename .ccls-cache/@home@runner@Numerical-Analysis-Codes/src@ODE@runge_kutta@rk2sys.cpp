#include <iostream>
#include <math.h>

#include "includes/rk2sys.h"

#define DEBUG

/* y'(x) = f(x,y) */
double rk2sys::f(double x, double y) {
  return (3 * x * x + 4 * x + 2) / (2 * (y - 1));
}

void rk2sys::solve(double x0, double y0, double h, double N) {
  printf("x0 = %f, y0 = %f\n", x0, y0);
  double x_pv = x0, y_pv = y0;
  for (auto i = 0; i < N; ++i) {
    double k1 = f(x_pv, y_pv);
    double k2 = f(x_pv + h, y_pv + h * k1);

    double y = y_pv + h * (0.5 * k1 + 0.5 * k2);
    double x = x + h;

    printf("x%d = %f, y%d = %f\n", i, x, i, y);
    x_pv = x;
    y_pv = y;
  }
}

#ifdef DEBUG
int main(int argc, char **argv) {
  rk2sys solver;
  solver.solve(0, -1, 0.1, 10);
}
#endif