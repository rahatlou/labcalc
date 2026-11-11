import numpy as np
import matplotlib.pyplot as plt

n, stima, errore = np.loadtxt('pigreco.txt', unpack=True)

plt.plot(n, errore, 'o', label='|stima - pi|')
plt.plot(n, 1 / np.sqrt(n), label=r'$1/\sqrt{N}$')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('numero di freccette N')
plt.ylabel('errore su pi')
plt.legend()
plt.grid()
plt.savefig('pigreco.png')
plt.show()
