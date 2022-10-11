# Differential Equations Solving methods

def Euler(u, f, t, dt):
    return u + f(t, *u) * dt

def RK2(u, f, t, dt):
    alpha = 3 / 4
    C = dt / (2 * alpha)
    k1 = f(t, *u)
    k2 = f(t + C, *u + C * k1)
    return u + dt * ((1 - alpha) * k1  + alpha * k2)

def RK4(u, f, t, dt):
    k1 = f(t, *u)
    k2 = f(t + (dt/2), *u + (dt/2) * k1)
    k3 = f(t + (dt/2), *u + (dt/2) * k2)
    k4 = f(t + dt, *u + dt * k3)
    return u + (dt / 6) * (k1 + 2 * k2 + 2 * k3 + k4)