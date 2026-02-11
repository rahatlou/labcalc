import numpy as np
import matplotlib.pyplot as plt

# --- lettura file ---
# ogni riga: turno pos_G1 pos_G2 ... pos_GN
data = np.loadtxt("posizione.txt", dtype=int)

turni = data[:, 0]
posizioni = data[:, 1:]

# numero di giocatori
N = posizioni.shape[1]

turni, G1, G2, G3, G4, G5 = np.loadtxt("posizione.txt", unpack=True)


plt.plot(turni, G1, label="Giocatore 1")
plt.plot(turni, G2, label="Giocatore 2")
plt.plot(turni, G3, label="Giocatore 3")
plt.plot(turni, G4, label="Giocatore 4")
plt.plot(turni, G5, label="Giocatore 5")

plt.xlabel("Turno")
plt.ylabel("Posizione")
plt.title("Gioco dell'Oca")
plt.legend()
plt.grid(True)

plt.savefig("oca.png")
plt.show()
