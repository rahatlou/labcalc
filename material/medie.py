# Esercitazione 6, Parte 1: istogramma delle medie e curva gaussiana prevista.
# Si esegue dopo medie.exe; a e ndati sono quelli usati nella simulazione.
import numpy as np
import matplotlib.pyplot as plt

a = 10.0
ndati = 30

media = np.loadtxt('medie.txt')            # una colonna: un array con le medie

mu = a / 2                                 # valore atteso della media
sigma = a / np.sqrt(12 * ndati)            # sigma prevista dal teorema del limite centrale
x = np.linspace(mu - 4 * sigma, mu + 4 * sigma, 200)
gauss = np.exp(-(x - mu) ** 2 / (2 * sigma ** 2)) / (sigma * np.sqrt(2 * np.pi))

plt.hist(media, bins=30, density=True, color='lightgreen', label='medie simulate')
plt.plot(x, gauss, color='red', label='gaussiana prevista')
plt.axvline(x=mu, color='blue', linestyle='--', label='valore atteso')
plt.xlabel('media di %d numeri' % ndati)
plt.ylabel('densita di probabilita')
plt.title('Distribuzione della media di numeri uniformi')
plt.grid()
plt.legend()
plt.savefig('medie.png')
plt.show()
