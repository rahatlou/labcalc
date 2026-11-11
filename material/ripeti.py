import numpy as np
import matplotlib.pyplot as plt

e, f = np.loadtxt('frequenze.txt', unpack=True)
sigma = np.sqrt(0.5 * (1 - 0.5) / 100)
etichetta = r'$\pm\sigma_f = \pm\sqrt{0.5 \cdot (1-0.5)/100}$'

plt.plot(e, f, 'o')
plt.axhline(0.5, color='red')
plt.axhline(0.5 + sigma, color='green', label=etichetta)
plt.axhline(0.5 - sigma, color='green')
plt.ylim(0.3, 0.7)
plt.xlabel('esperimento')
plt.ylabel('frequenza di teste su 100 lanci')
plt.legend()
plt.grid()
plt.savefig('frequenze.png')
plt.show()
