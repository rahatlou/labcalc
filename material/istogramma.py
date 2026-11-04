import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt('casuali.txt')   # uno per riga

plt.hist(x, bins=10)
plt.xlabel('valore')
plt.ylabel('conteggi')
plt.title('100000 numeri con drand48()')
plt.savefig('istogramma.png')
plt.show()
