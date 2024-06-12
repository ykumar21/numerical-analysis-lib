#include "Polynomial.h"

Polynomial::Polynomial(size_t n, double *coeff) {
    this->degree = n;
    this->coeff = (double*) malloc(this->degree * sizeof(double));
    for ( auto i = 0; i < n; ++i ) {
        this->coeff[i] = coeff[i];
    }
};