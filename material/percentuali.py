# Esercitazione 6, Parte 3: frazione di medie entro 1 e 2 sigma dal valore atteso.
import numpy as np
import matplotlib.pyplot as plt

ndati, u1, e1, u2, e2 = np.loadtxt('percentuali.txt', unpack=True)

plt.plot(ndati, u1, 'o-', color='green', label='uniformi, entro 1 sigma')
plt.plot(ndati, e1, '^-', color='blue', label='esponenziali, entro 1 sigma')
plt.plot(ndati, u2, 'o--', color='green', label='uniformi, entro 2 sigma')
plt.plot(ndati, e2, 'x--', color='blue', label='esponenziali, entro 2 sigma')
plt.axhline(y=0.6827, color='red', linestyle=':', label='gaussiana, entro 1 sigma: 0.6827')
plt.axhline(y=0.9545, color='red', linestyle='-.', label='gaussiana, entro 2 sigma: 0.9545')
plt.xscale('log')
plt.xlabel('numero di dati per esperimento')
plt.ylabel('frazione di medie')
plt.title('Frazione delle medie entro 1 e 2 sigma')
plt.grid()
plt.legend()
plt.savefig('percentuali.png')
plt.show()
