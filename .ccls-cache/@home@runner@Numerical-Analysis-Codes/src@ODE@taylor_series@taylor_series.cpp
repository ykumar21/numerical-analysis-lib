#include "includes/taylor_series.h"
#include <iostream>
#include <math.h>

typedef double (*F)(double);


#ifdef DEBUG

double f_1(double x) { return sqrt(x); }
double f_2(double x) { return 0.5 * pow(x, -1.5); };


int main(int argc, char **argv) {
  double x0 = 0;
  double N = 20;
  double h = 0.2;
  F *d = (F*) malloc(2 * sizeof(F));
    d[0] = f_1;
    d[1] = f_2;
    
    TaylorSeriesODE<F> solver;
    solver.solve(0,0.15,20, d);
}
#endif
