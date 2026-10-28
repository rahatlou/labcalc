import numpy as np

GRAV = 9.81
t = np.linspace(0, 2, 5)
y = 20 - 0.5 * GRAV * t ** 2
print(t)
print(y)
print(np.arange(0, 1, 0.25))
print(np.sqrt(16), np.sin(np.pi / 2))
print(len(t))
