import numpy as np
import matplotlib.pyplot as plt

x = np.loadtxt('intervalli_prob.txt')   # uno per riga

plt.hist(x, bins=28)               # intervalli larghi 0.25
plt.xlabel('valore')
plt.ylabel('conteggi')
plt.title('tre intervalli con probabilita 50%, 30%, 20%')
plt.savefig('intervalli_prob.png')
plt.show()
