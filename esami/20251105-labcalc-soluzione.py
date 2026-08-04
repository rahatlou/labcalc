import numpy as np
import matplotlib.pyplot as plt

# Carica i dati con NumPy
segnale = np.loadtxt("segnale.txt")
fondo = np.loadtxt("fondo.txt")

# Istogramma
#plt.hist(segnale, bins=30, alpha=0.7, label="Segnale", density=True)
#plt.hist(fondo, bins=30, alpha=0.7, label="Fondo", density=True)

plt.hist(fondo,  label="Fondo")
plt.hist(segnale, label="Segnale")


plt.xlabel("Massa [GeV]")
plt.ylabel("unita arbit.")
plt.title("Distribuzione delle masse generate")
plt.legend()
plt.grid(alpha=0.3)

plt.show()
