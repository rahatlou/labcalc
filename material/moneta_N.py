import numpy as np
import matplotlib.pyplot as plt

n, f, scarto = np.loadtxt('moneta.txt', unpack=True)

plt.plot(n, scarto, 'o', label='scarto')
plt.plot(n, 1 / np.sqrt(n), label=r'$1/\sqrt{N}$')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('numero di lanci N')
plt.ylabel('scarto da 0.5')
plt.legend()
plt.grid()
plt.savefig('moneta.png')
plt.show()
