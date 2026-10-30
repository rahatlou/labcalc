import matplotlib.pyplot as plt
import numpy as np

n, fib, rapporto = np.loadtxt('fibonacci.txt', unpack=True)

plt.bar(n, fib)
plt.yscale('log')
plt.xlabel('n')
plt.ylabel('F(n)')
plt.show()
