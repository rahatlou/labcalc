# Esercitazione 4, esercizio facoltativo: errore in scala logaritmica.
# Servono babilon_1.txt (eps = 0.001, r0 = 1, a = 7) e babilon_30.txt (eps = 0.001, r0 = 30, a = 7),
# ottenuti con: cp babilon.txt babilon_1.txt   (dopo la prima esecuzione) e cp babilon.txt babilon_30.txt (dopo la seconda).
import numpy as np
import matplotlib.pyplot as plt

A = 7.
n1, r1 = np.loadtxt('babilon_1.txt', unpack=True)
n2, r2 = np.loadtxt('babilon_30.txt', unpack=True)

err1 = np.abs(r1 - np.sqrt(A))      # errore a ogni passo: un array
err2 = np.abs(r2 - np.sqrt(A))

plt.plot(n1, err1, 'o-', label='r0 = 1')
plt.plot(n2, err2, 'x-', label='r0 = 30')
plt.yscale('log')
plt.xlabel('iterazione n')
plt.ylabel('errore |r_n - sqrt(a)|')
plt.title('Errore del metodo babilonese')
plt.grid()
plt.legend()
plt.savefig('errore.png')
plt.show()
