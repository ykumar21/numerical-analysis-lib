#include <stdlib.h> 
#include <iostream>

#include "includes/circulant_matrix.h"

using namespace std; 

CirculantMatrix::CirculantMatrix(unsigned int n) {
    this->n = n; 
    // Allocate the matrix 
    matrix = (double*) malloc(n*);
}
