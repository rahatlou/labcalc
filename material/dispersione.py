# Esercitazione 5, esercizio facoltativo: sigma delle stime di pi in funzione di N_lanci.
# Si esegue dopo dispersione.exe, che scrive dispersione.txt (N_lanci e sigma).
import numpy as np
import matplotlib.pyplot as plt

nlanci, sigma = np.loadtxt('dispersione.txt', unpack=True)

plt.plot(nlanci, sigma, 'o', label='sigma delle stime')
plt.plot(nlanci, 3.3 / np.sqrt(nlanci), label='3.3 / sqrt(N)')
plt.xscale('log')
plt.yscale('log')
plt.xlabel('numero di lanci')
plt.ylabel('sigma')
plt.title('Dispersione delle stime di pi')
plt.grid()
plt.legend()
plt.savefig('dispersione.png')
plt.show()
