#include "euler_method.h"
#include <iostream>
#include <math.h>

typedef double (*F)(double);

#define DEBUG

double f(double x) { return sqrt(x); }

#ifdef DEBUG
int main(int argc, char **argv) {
  double x0 = 0;
  double N = 20;
  double h = 0.2;
  F func_ptr = f;
  EulerMethod<F> solver(x0, h, N, f);
}
#endif
