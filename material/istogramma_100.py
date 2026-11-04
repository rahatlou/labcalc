import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt('casuali.txt')   # uno per riga

plt.hist(x[:100], bins=10)      # solo i primi 100
plt.xlabel('valore')
plt.ylabel('conteggi')
plt.title('100 numeri con drand48()')
plt.savefig('istogramma_100.png')
plt.show()
