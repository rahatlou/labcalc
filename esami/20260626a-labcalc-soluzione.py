import numpy as np
import matplotlib.pyplot as plt

t, xideal, x = np.loadtxt("posizione.dat",
                          unpack=True)

plt.plot(t,
         xideal,
         label="posizione ideale")

plt.plot(t,
         x,
         label="posizione misurata")

plt.xlabel("tempo [s]")
plt.ylabel("posizione [m]")

plt.title("Oscillatore armonico")

plt.legend()

plt.grid()

plt.savefig("oscillatore.png")

plt.show()
