import matplotlib.pyplot as plt
import numpy as np
import math as m

piatto, sinx, expx = np.loadtxt("numeri.txt", unpack=True)

nbins=20

plt.title("Numeri casuali generati con 3 diverse distribuzioni, nbins=%d"%(nbins))

plt.xlim(0, m.pi)
plt.xlabel('variabile casuale x')
plt.ylabel('numero eventi')

plt.hist(piatto, bins=nbins, histtype='step', label='uniforme')

plt.hist(sinx, bins=nbins, histtype='step', color='red', label='$sin(x)$')

plt.hist(expx, bins=nbins, histtype='step', color='green', label="$e^{-x}$")

# legenda dei 3 grafici
plt.legend(loc="upper right")


plt.show()

