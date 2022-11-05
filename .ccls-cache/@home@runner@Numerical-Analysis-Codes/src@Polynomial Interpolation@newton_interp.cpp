#include <iostream> 
#include <stdlib.h> /* malloc */ 

class NewtonInterp {
private: 
    size_t N; 
    double *x, *y; 
    double *basis;
    void compute_basis();
public:    
    NewtonInterp(size_t, double *, double *);
    double* eval(size_t, double*);
};

NewtonInterp::NewtonInterp(size_t N, double *x, double *y) {
    this->N = N; 
    this->x = (double*) malloc(N * sizeof(double));
    this->y = (double*) malloc(N * sizeof(double));
    for (int i = 0; i < N; ++i) {
        this->x[i] = x[i];
        this->y[i] = y[i];
    }

    // compute the basis 
    compute_basis();
}

void NewtonInterp::compute_basis() {
    basis = (double*) malloc(N * N * sizeof(double));
    for (auto i = 0; i < N; ++i) {
        basis[i*N] = y[i];
    }
    for ( auto i = 0; i < N; ++i ) {
        for ( auto j = 0; j < N-i; ++j ) {
            basis[j*N + i] = ( basis[j*N + i-1] - basis[(j+1)*N + i -1] ) / ( x[j] - x[i+j] );
        }
    }
}

double* NewtonInterp::eval(size_t num_points, double *x_test) {
    double *p_x = (double*) malloc(num_points * sizeof(double));
    for (auto v = 0; v < num_points; ++v) {
        double cur_x = x_test[v];
        double total_sum = 0;
        for ( auto i = 0; i < N; ++i ) {
            double partial_sum = basis[i]; // f[x0,x1,...,xi]
            for ( auto j = 0; j < i; ++j ) {
                partial_sum *= ( cur_x - x[j] );
            }
            total_sum += partial_sum;
        }
        p_x[v] = total_sum;
    }
    return p_x;
}

#ifdef DEBUG
void* driver (void *args) {
    size_t N; 
    printf("Enter number of points: ");
    std::cin >> N; 

    double *x = (double*) malloc(N * sizeof(double));
    double *y = (double*) malloc(N * sizeof(double));

    for ( auto i = 0; i < N; ++i ) {
        printf("Enter (x%d,y%d): ", i, i);
        std::cin >> x[i] >> y[i];
    }

    NewtonInterp interpolator(N, x, y);
    interpolator.eval(N,x);
    return nullptr;
}

int main(int argc, char** argv) {
    driver(nullptr);
}
#endif 