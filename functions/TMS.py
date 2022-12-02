# Tridiagonal Matrix Solver
def TMS(a, b, c, f):
    n = f.size
    
    for i in range(1, n):
        w = a[i] / b[i - 1]
        b[i] -= w * c[i - 1]
        f[i] -= w * f[i - 1]
    
    x = np.zeros(n)
    x[n - 1] = f[n - 1] / b[n - 1]
    
    for i in range(n - 2, -1, -1):
        x[i] = (f[i] - c[i] * x[i + 1]) / b[i]
    
    return x