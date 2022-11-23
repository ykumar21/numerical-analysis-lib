#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <stddef.h> /* size_t */ 
#include <stdlib.h> /* malloc */ 

class Polynomial {
private:    
    size_t degree; 
    double *coeff; 
public: 
    Polynomial(size_t, double*);
};

#endif