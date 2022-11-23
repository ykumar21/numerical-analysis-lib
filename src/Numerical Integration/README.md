## Numerical Integration

Numerical integration is the procedure to estimate the integral $\int_{a}^{b} f(x)dx$ numerically. 

### 1. Newton-Cotes Method
Suppose we have to calculate the integral $\int_{a}^b f(x)dx$. We can generate the interpolating polynomial, $$p(x) = \sum_{i=0}^N f(x_{i}) \prod_{j \neq i}^N \frac{x-x_j}{x_i - x_j}$$
Then, the integral $\int_{a}^b f(x)dx$ can be approximated as $$\int_{a}^b f(x)dx = \int_{a}^b p(x)dx = \sum_{i=0}^N f(x_{i}) \int_{a}^b \prod_{j \neq i}^N \frac{x-x_i}{x_i - x_j}dx$$

So, we obtain the following formula $$\int_{a}^b f(x)dx = \sum_{i=1}^N A_{i}f(x_{i})$$
where 
$$A_{i} = \int_{a}^b \prod_{j \neq i}^N \frac{x - x_j}{x_i - x_j}dx$$
### 2. Composite Trapazoid 

Suppose we have to calculate the integral $\int_{a}^{b}f(x)dx$ and the interval [a,b] is partitioned as $$a = x_0 < x_1 < ... < x_n = b$$
Then, we can apply the trapezoid rule to each subinterval $[x_{i-1}, x_{i}]$. Thus, we obtain the following composite trapezoid rule: 
$$\int_{a}^{b} f(x)dx = \sum_{i = 1}^N \int_{x_{i-1}}^{x_{i}}f(x)dx =\frac{1}{2} \sum_{i=1}^N (x_i - x_{i-1}) [f(x_i) + f(x_{i-1})]$$
