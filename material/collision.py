import matplotlib.pyplot as plt
import numpy as np
import math as m

# leggere i dati dal file
fname = "atomi.txt"
# chiedere il nome del file all'utente
#fname = input("nome file per i dati: ")
xa,ya = np.loadtxt(fname, unpack=True)


# grafico degli atomi
#plt.plot(xa,ya, marker='.', color='blue', alpha=0.1, label='atomi nel bersaglio')

# piu` correttamente usare scatter per non avere la linea tra i punti
plt.scatter(xa,ya, marker='.', color='blue', alpha=0.1, label='atomi nel bersaglio')

# ========== estetica e info opzionali ==========

# trovare valori di Natomi, A e B dai dati
A = max(xa)
B = max(ya)
Natomi = len(xa)

print("%d atomi con semiassi del bersaglio A: %.1f, B: %.1f"%(Natomi,A,B))

# info del grafico
plt.title("Distribuzione di %d atomi nel bersaglio con A=%.1f, B=%.1f"%(Natomi,A,B))
plt.xlabel("coordinata $x$ degli atomi")
plt.ylabel("coordinata $y$ degli atomi")

# equazione parametrica per grafica l'ellisse
theta = np.linspace(0, 2*np.pi, 100)
plt.plot( A*np.cos(theta), B*np.sin(theta), 'r-', label='bordo bersaglio')

# impostare limiti del grafico in modo automatico aggiungendo 30% a dx, sx, sopra e sotto
xmin = -A*1.3
xmax = -xmin

ymin = -B*1.3
ymax = -ymin

plt.xlim(xmin, xmax)
plt.ylim(ymin, ymax)

# indicare i semiassi
plt.arrow(0,0,A,0, color='green')
plt.arrow(0,0,0,B, color='green')

# legenda
plt.legend(loc="upper left")

# ========== estetica e info opzionali ==========

plt.show()

