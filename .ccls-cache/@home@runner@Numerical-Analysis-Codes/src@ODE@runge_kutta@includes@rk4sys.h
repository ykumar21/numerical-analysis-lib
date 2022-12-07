#ifndef RK4SYS_H
#define RK4SYS_H

class rk4sys {
private:
  double f(double, double);

public:
  void solve(double, double, double, double);
};

#endif