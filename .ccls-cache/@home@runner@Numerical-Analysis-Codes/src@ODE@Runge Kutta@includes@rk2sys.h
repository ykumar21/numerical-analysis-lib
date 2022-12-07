#ifndef RK2SYS_H
#define RK2SYS_H

/* Approximates the solution of
 * an ODE using second order Runge
 * Kutta method
 */
class rk2sys {
private:
  double f(double, double);

public:
  void solve(double, double, double, double);
};

#endif