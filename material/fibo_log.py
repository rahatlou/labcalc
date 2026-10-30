import matplotlib.pyplot as plt
import numpy as np

n, fib, rapporto = np.loadtxt('fibonacci.txt', unpack=True)

plt.plot(n, fib, 'o')
plt.yscale('log')
plt.xlabel('n')
plt.ylabel('F(n)')
plt.grid()
plt.show()
