/*
 * Approximates the solution to an ordinary 
 * differential equation using taylor series
 * expansion
 */

#ifndef TAYLOR_SERIES_ODE_H
#define TAYLOR_SERIES_ODE_H 

#include <iostream> 

#define ORDER 3 

template <typename F> class TaylorSeriesODE {
public: 
    void solve(double, double, double, F*);
};

template <typename F> 
void TaylorSeriesODE<F>::solve(double x0, double h, double N, F *d) {
    double prev_x = x0; 
    double prev_y = d[0](x0);
    
    for (int i = 0; i < N; ++i) {
        printf("Step %d\n", i);
        double yi = prev_y + h * (d[0](prev_x) + h/2 * d[1](prev_x));
        double xi = prev_x + h;
        printf("X_%d = %f, Y_%d = %f\n", i, xi, i, yi);
        prev_x = xi;
        prev_y = yi;
    }
}

#endif