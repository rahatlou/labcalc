import numpy as np
import matplotlib.pyplot as plt

# carica i dati dal file
# colonne: indice   temperatura
indice, temperatura = np.loadtxt("temperatura.dat", unpack=True)

# grafico della distribuzione della temperatura
plt.plot(indice, temperatura, marker='o',
         label="Temperatura lungo la sbarra")

plt.xlabel("Indice")
plt.ylabel("Temperatura [kelvin]")
plt.title("Andamento della temperatura")

plt.grid(True)
plt.legend()

plt.savefig("temperatura.png")
plt.show()
