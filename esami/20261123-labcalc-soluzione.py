import numpy as np
import matplotlib.pyplot as plt

# capitale del primo investitore in funzione del giorno
giorno, capitale = np.loadtxt("capitale.dat", unpack=True)

plt.plot(giorno, capitale, label="capitale")
plt.axhline(10000, color="red", linestyle="--", label="capitale iniziale")
plt.xlabel("giorno")
plt.ylabel("capitale [euro]")
plt.title("Andamento del capitale")
plt.legend()
plt.grid(alpha=0.3)
plt.savefig("capitale.png")
plt.show()
