#ifndef EULER_METHOD_H
#define EULER_METHOD_H

#include <iostream>

template <typename F> class EulerMethod {
private:
  double x0;
  double h;
  unsigned int N;
  F f;
  void solve();

public:
  EulerMethod(double, double, unsigned int, F f);
};

template <typename F> void EulerMethod<F>::solve() {
  double prev_x = x0;
  double prev_y = f(x0);
  for (int i = 1; i <= N; ++i) {
    double xi = prev_x + h;
    double yi = prev_y + h * f(prev_x);
    printf("X_%d = %f ", i, xi);
    printf("Y_%d = %f\n", i, yi);
    prev_x = xi;
    prev_y = yi;
  }
}

template <typename F>
EulerMethod<F>::EulerMethod(double x0, double h, unsigned int N, F f) {
  this->x0 = x0;
  this->h = h;
  this->N = N;
  this->f = f;
  solve();
}
#endif