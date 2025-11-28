# codice python soggetto a valutazione
import matplotlib.pyplot as plt
import numpy as np

fname = "grani.txt"
Na, Nb, Nc = np.loadtxt(fname, unpack=True)
nexp = np.arange(len(Na))

plt.title("Numero di grani verso numero di simulazione")
plt.xlabel("numero simulazione")
plt.ylabel("numero grani")


plt.plot(nexp, Na,  '--', color = 'b', label="$N_A$", alpha=0.7)
plt.plot(nexp, Nb, color = 'red', linestyle= '--', label="$N_B$" , alpha=0.7)
plt.plot(nexp, Nc, 'g--', label="$N_C$" , alpha=0.7)


### codice opzionale non soggetto a valutazione
ymax = 1.6*max(max(Na), max(Nb), max(Nc))
plt.ylim(-10,ymax)

# calcolo valore medio di Na, Nb, Nc
#
m_A = np.mean(Na)
plt.axhline(y=m_A, color='blue', linestyle='-', label="<$N_A$> = %.1f"%m_A)

m_B = np.mean(Nb)
plt.axhline(y=m_B, color='red', linestyle='-', label="<$N_B$> = %.1f"%m_B)

m_C = np.mean(Nc)
plt.axhline(y=m_C, color='green', linestyle='-', label="<$N_C$> = %.1f"%m_C)


#### fine opzionale

plt.legend(loc="upper right")

plt.show()
