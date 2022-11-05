#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <stddef.h>

template <typename T> class Matrix {
private:
  size_t M;
  size_t N;
  T *matrix;

public:
  Matrix(size_t, size_t);
  T get(size_t, size_t);
  void *put(size_t, size_t, T);
};

template <typename T> Matrix<T>::Matrix(size_t M, size_t N) {
  this->M = M;
  this->N = N;
  matrix = (T *)malloc(M * N * sizeof(T));
}

template <typename T> T Matrix<T>::get(size_t row, size_t col) {
  return matrix[row * N + col];
}

template <typename T> void *Matrix<T>::put(size_t row, size_t col, T el) {
  matrix[row * N + col] = el;
  return nullptr;
}

#endif