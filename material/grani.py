# codice python soggetto a valutazione
import matplotlib.pyplot as plt
import numpy as np

fname = "grani.txt"
Na, Nb, Nc = np.loadtxt(fname, unpack=True)
nexp = np.arange(1000)

plt.title("Numero di grani verso numero di simulazione")
plt.xlabel("numero simulazione")
plt.ylabel("numero grani")


plt.plot(nexp, Na, 'b--', label="$N_A$")
plt.plot(nexp, Nb, 'r--', label="$N_B$")
plt.plot(nexp, Nc, 'g--', label="$N_C$")


### codice opzionale non soggetto a valutazione
ymax = 1.5*max(max(Na), max(Nb), max(Nc))
plt.ylim(-10,ymax)

m_A = np.mean(Na)
plt.axhline(y=m_A, color='blue', linestyle='--', label="<$N_A$> = %.1f"%m_A)

m_B = np.mean(Nb)
plt.axhline(y=m_B, color='red', linestyle='--', label="<$N_B$> = %.1f"%m_B)

m_C = np.mean(Nc)
plt.axhline(y=m_C, color='green', linestyle='--', label="<$N_C$> = %.1f"%m_C)


#### fine opzionale

plt.legend(loc="upper right")

plt.show()