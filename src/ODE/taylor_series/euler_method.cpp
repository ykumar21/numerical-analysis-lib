

#include "includes/euler_method.h"
#include <iostream>
#include <math.h>

#ifdef DEBUG

typedef double (*F)(double);

double f(double x) { return sqrt(x); }


int main(int argc, char **argv) {
  double x0 = 0;
  double y0 = 0;
  double N = 20;
  double h = 0.2;
  F func_ptr = f;
  EulerMethod<F> solver(x0, y0, h, N, f);
}
#endif
