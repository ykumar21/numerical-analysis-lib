#include <iostream>
#include <math.h>
class rk4sys {
private:
  double f(double x, double y) {
    /* Enter your function here */
    return cos(x) - sin(y) + x * x;
  }

public:
  void solve(double x, double y, double h, double N) {
    printf("x = %f, y = %f\n", x, y);
    for (int i = 0; i < N; ++i) {
      double f1 = h * f(x, y);
      double f2 = h * f(x + h / 2, y + 0.5 * f1);
      double f3 = h * f(x + h / 2, y + 0.5 * f2);
      double f4 = h * f(x + h, x + f3);
      y = y + (f1 + 2 * f2 + 2 * f3 + f4) / 6;
      x = x + h;
      printf("x = %f, y = %f\n", x, y);
    };
  };
};

#ifdef DEBUG
int main(int argc, char **argv) {
  rk4sys solver;
  solver.solve(-1, 3, 0.2, 10);
}
#endif