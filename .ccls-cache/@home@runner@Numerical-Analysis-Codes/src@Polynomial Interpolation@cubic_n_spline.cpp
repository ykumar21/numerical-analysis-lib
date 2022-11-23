/*
 * Generates a natural cubic spline for 
 * the given data points.
 */ 
#include "./../Common/Polynomial.h"

class CubicSpline {
private: 
    size_t N;      /* number of points */ 
    double *x;     /* knot values */  
    double *y;     /* function values */ 
public: 
    CubicSpline(size_t, double*, double*);
    double *eval();    
};