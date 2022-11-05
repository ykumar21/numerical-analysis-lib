#include <iostream> 
#include <stdlib.h> 
#include <stddef.h>

class GradientDescent {
private:
    double *A;    // SPD matrix 
    double *b;    // values 
    size_t num_eq; // number of eqns 
public: 
    GradientDescent(size_t, double*, double*);
};