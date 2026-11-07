# Esercitazione 4, Parte 1: grafico della convergenza del metodo babilonese.
# Si esegue dopo babilon.exe (dati di prova: eps = 0.001, r0 = 1, a = 7), che scrive babilon.txt.
import numpy as np
import matplotlib.pyplot as plt

A = 7.    # lo stesso valore di a usato nel programma C
n, r = np.loadtxt('babilon.txt', unpack=True)    # una colonna del file, un array

plt.plot(n, r, 'o-', label='stima babilonese')
plt.axhline(y=np.sqrt(A), color='red', linestyle='--', label='sqrt(a)')
plt.xlabel('iterazione n')
plt.ylabel('stima di sqrt(a)')
plt.title('Metodo babilonese, a = 7')
plt.grid()
plt.legend()
plt.savefig('convergenza.png')     # prima di show
plt.show()
