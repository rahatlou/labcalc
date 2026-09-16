import numpy as np
import matplotlib.pyplot as plt

N, cumulativa, prob = np.loadtxt("cumulativa.dat", unpack=True)

plt.plot(N, cumulativa, label="Simulazione")
plt.plot(N, prob, label="Teoria")

plt.xlabel("Numero di estrazioni")
plt.ylabel("Probabilità cumulativa")
plt.legend()

plt.savefig("cumulativa.png")
plt.show()
