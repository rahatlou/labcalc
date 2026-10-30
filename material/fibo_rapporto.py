import matplotlib.pyplot as plt
import numpy as np

n, fib, rapporto = np.loadtxt('fibonacci.txt', unpack=True)

aurea = (1. + np.sqrt(5.)) / 2.
plt.plot(n, rapporto, 'o', label='F(n+1) / F(n)')
plt.axhline(y=aurea, color='red', linestyle='--', label='sezione aurea')
plt.xlabel('n')
plt.legend()
plt.show()
