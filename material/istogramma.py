# carica moduli pyplot, numpy e matematica di python
import matplotlib.pyplot as plt
import numpy as np
import math as m

# carica dati dal file
# exp sono numero di esperimenti nella prima colonna
# pi sono le stime nella seconda colonna
exp, pi = np.loadtxt('pigreco.dat', unpack=True)

# numero di esperimenti si calcola dalla lunghezza dell'array di dati con la funzione len()
print("totale esperimenti: %d"%len(pi))

# calcolo valore medio con la funzione np.average( array )
print("valore medio pi: %.5f"%(np.average(pi)))

plt.title("Andamento di $\pi$ in funzione di esperimento")

# crea grafica di stima in funzione di iter
plt.plot( exp, pi, '.', label='stima di $\pi$ con ago di buffon')

# specifica limite inferiore superiore per asse x e y con numeri opportuni in base ai vostri dati
plt.xlim(0, 1000)
plt.ylim(2.5, 4)

# aggiungi legenda per gli assi
plt.xlabel('#esperimento')
plt.ylabel('$\pi$ stimato')

# linea orizzontale rossa al valore di pi greco usando la libreria matematica
plt.axhline( y=m.pi, color = 'red', linestyle='--')

# nome del file in cui salvare il grafico
plt.savefig("pi.png")

# mostra grafico
plt.show()
##
####  istogramma della distribuzione di pi greco
##
## fit ai dati con una distribuzione gaussiana per calcolo della media e della larghezza
from scipy.stats import norm
(mu,sigma) = norm.fit(pi)

# differenza con valore di lib  matematica
print("pi - <pi> = %.5g"%(m.pi-mu))

# stampa formattata sullo schermo in due possibili modi diversi
print("<pi>: %.5f mu: %.5f sigma: %.5f"%(np.average(pi), mu,sigma)) 

print("<pi>: %.5f"%np.average(pi), "mu: %.5f"%mu, "sigma: %.5f"%sigma) 

print("valore stimato di pi: %.4f  incertezza: %.4f"%(mu, sigma/m.sqrt(len(pi))))


# titolo riporta i valori di mu e sigma ottenuti con il fit
plt.title(r"Distribuzione stime $\pi$ greco: $<\pi>$=%.5f $\sigma$=%.5f"%(mu,sigma))

# istogramma dei valori letti dal file
plt.hist(pi, color='green', bins=12)
plt.xlabel("$\pi$ stimato")
plt.ylabel("# esperimenti")

# valore vero di pi greco
plt.axvline( x=m.pi, color = 'blue', linestyle='dotted')
# valore stimato dai dati
plt.axvline( x=mu, color = 'red', linestyle='--')

plt.show()



