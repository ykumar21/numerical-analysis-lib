# Polynomial Interpolation

Polynomial Interpolation is the process to fit a polynomial $P(x)$ to a set of datapoints $\{x_0, x_1, ..., x_n\}$ such that 
$P(x_i) = y_i \forall i \in [0,N]$.

## Implemented Algorithms 
1. Lagrange Interpolation 
2. Newton Interpolation

### 1. Lagrange Interpolation 
In Lagrange Interpolation, we generate a polynomial, $P(x) \in \Pi_N$, using Lagrange basis functions $l_i(x), 0 \leq i \leq N$ such that  $$l_i(x) =  \delta_{ij} = \prod_{j = 0}^{N} \frac{x - x_j}{x_i - x_j}, 0 \leq i \leq N$$

The Lagrange interpolating polynomial $P(x)$ is computed as follows: $$P(x) = \sum_{i=0}^N y_i l_i(x) = \sum_{i=0}^N y_i (\prod_{j = 0}^{N} \frac{x - x_j}{x_i - x_j})$$

In our implementation, the run time of computing the lagrange interpolating polynomial is $O(N^2)$. 

### 2. Newton Interpolation 
In Newton Interpolation, we generate a polynomial, $P(x) \in \Pi_N$, using divided differences $f[x_0, x_1, ..., x_i]$ where 
$$f[x_j, x_{j+1}, ..., x_i] = \frac{f[x_{j+1}, x_{j+2}, ..., x_{i}] - f[x_{j+1}, x_{j+2}, ..., x_{i-1}]}{x_i - x_j}, 0 \leq j < i \leq N  $$

The required interpolating polynomial, $P(x)$ is given by $$P(x) = \sum_{i=0}^{N} f[x_0, x_1,..,x_i] \prod_{j = 0}^{j < i} x - x_j$$

In our implementation, the runtime of computing the newton interpolating polynomial is $O(N^2)$
