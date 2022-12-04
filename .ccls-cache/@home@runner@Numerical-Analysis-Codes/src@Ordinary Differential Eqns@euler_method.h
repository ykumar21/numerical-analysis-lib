#include <iostream>

template <typename F>
class EulerMethod {
private:
    void solve(unsigned int);
public: 
    EulerMethod(double, unsigned double, F f);
};

template <typename F> 
EulerMethod<F>::EulerMethod(double x0, unsigned double h, F f) {
    
}

int main(int argc, char **argv) {
    std::cout << "Hello World!";
}