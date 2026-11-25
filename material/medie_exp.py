# Esercitazione 6, Parte 2: istogramma delle medie di numeri esponenziali.
# Si esegue dopo medie_exp.exe; tau e ndati sono quelli usati nella simulazione.
import numpy as np
import matplotlib.pyplot as plt

tau = 2.0
ndati = 30

media = np.loadtxt('medie_exp.txt')

mu = tau                                   # valore atteso della media
sigma = tau / np.sqrt(ndati)               # sigma prevista dal teorema del limite centrale
x = np.linspace(mu - 4 * sigma, mu + 4 * sigma, 200)
gauss = np.exp(-(x - mu) ** 2 / (2 * sigma ** 2)) / (sigma * np.sqrt(2 * np.pi))

plt.hist(media, bins=30, density=True, color='orange', label='medie simulate')
plt.plot(x, gauss, color='red', label='gaussiana prevista')
plt.axvline(x=mu, color='blue', linestyle='--', label='valore atteso')
plt.xlabel('media di %d numeri esponenziali' % ndati)
plt.ylabel('densita di probabilita')
plt.title('Medie di numeri esponenziali')
plt.grid()
plt.legend()
plt.savefig('medie_exp.png')
plt.show()
