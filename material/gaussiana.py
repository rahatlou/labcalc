import numpy as np
import matplotlib.pyplot as plt

MU = 25.00
SIGMA = 0.04
x = np.loadtxt('misure.txt')

plt.hist(x, bins=40, density=True, label='dati')
xx = np.linspace(MU - 4. * SIGMA, MU + 4. * SIGMA, 200)
f = np.exp(-(xx - MU)**2 / (2. * SIGMA**2))
f = f / (SIGMA * np.sqrt(2. * np.pi))
plt.plot(xx, f, 'r-', label='formula')
plt.xlabel('misura (mm)')
plt.ylabel('densita')
plt.title('100000 misure, mu = 25.00 mm, sigma = 0.04 mm')
plt.legend()
plt.savefig('gaussiana.png')
plt.show()
