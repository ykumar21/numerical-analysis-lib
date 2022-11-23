// #include "./../Common/Matrix.h"
// #include <iostream>
// #include <stddef.h>
// #include <stdlib.h>

// class GradientDescent {
// private:
//   const unsigned int CACHE_SZ = 1;

//   Matrix<double> *A;     // SPD matrix
//   Matrix<double> *b;     // value vector
//   size_t num_eq;         // number of eqns
//   Matrix<double> *cache; // cache of size one
//   void step();           // single step of gradient descent

// public:
//   GradientDescent(size_t, Matrix<double> *, Matrix<double> *);
// };

// GradientDescent::GradientDescent(size_t num_eq, Matrix<double> *A,
//                                  Matrix<double> *b) {
//   this->A = A;
//   this->b = b;
//   this->num_eq = num_eq;
//   cache = (Matrix<double> *)malloc(CACHE_SZ * sizeof(Matrix<double>));
// }

// void GradientDescent::step() {
//   Matrix<double> x_prev = cache[0];
//   Matrix<double> d_k = ;
//   double alpha_k = (d_k.transpose() * d_k) / (d_k.transpose() * A * d_k);
//   Matrix<double> x_k = x_prev + alpha_k * (b - A * x_prev);
//   cache[0] = x_k;
// }
