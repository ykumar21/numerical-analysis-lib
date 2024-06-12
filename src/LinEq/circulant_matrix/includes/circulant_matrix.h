#ifndef CIRCULANT_MATRIX 
#define CIRCULANT_MATRIX 

class CirculantMatrix {
private: 
    unsigned int n; // Size of the matrix 
    double *matrix = nullptr;
public: 
    CirculantMatrix(unsigned int); 
};

#endif