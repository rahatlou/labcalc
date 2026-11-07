# Esercitazione 4, Parte 2: confronto dei due metodi sullo stesso grafico.
# Servono babilon.txt (eps = 0.001, r0 = 1, a = 7) e radice.txt (eps = 0.001, a = 7).
import numpy as np
import matplotlib.pyplot as plt

A = 7.
n1, r = np.loadtxt('babilon.txt', unpack=True)
n2, s = np.loadtxt('radice.txt', unpack=True)     # s = 1/y_n

# il secondo metodo parte dopo due passi del primo: il suo passo n corrisponde a n + 2
plt.plot(n1, r, 'o-', label='babilonese')
plt.plot(n2 + 2, s, 'x-', color='green', label='1/y_n')
plt.axhline(y=np.sqrt(A), color='red', linestyle='--', label='sqrt(a)')
plt.xlim(-0.2, 5.5)
plt.ylim(2.6, 3.0)          # i limiti si scelgono guardando i dati: i primi punti del metodo babilonese sono fuori
plt.xlabel('iterazione (contando anche i due passi iniziali)')
plt.ylabel('stima di sqrt(a)')
plt.title('Due metodi per sqrt(7)')
plt.grid()
plt.legend()
plt.savefig('confronto.png')
plt.show()
