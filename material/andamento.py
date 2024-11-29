# carica moduli pyplot, numpy e matematica di python
import matplotlib.pyplot as plt
import numpy as np
import math as m

# carica dati dal file
# prima colonna -> passi,   seconda colonna -> distfin
passi, distfin = np.loadtxt('distfin.txt', unpack=True)

# numero di esperimenti si calcola dalla lunghezza dell'array di dati con la funzione len()
print("numero simulazioni: %d"%len(passi))

plt.title("Andamento di distanza finale media in funzione di $N_{passi}$")

# crea grafica di distfin in funzione del numero di passi
plt.plot( passi, distfin, 'o-', label='')

# specifica limite inferiore superiore per asse x e y con numeri opportuni in base ai vostri dati
plt.xlim(0, 600)
plt.ylim(0., 20)

# aggiungi legenda per gli assi
plt.xlabel('$N_{passi}$')
plt.ylabel('distanza finale media dall\'origine')

# nome del file in cui salvare il grafico
plt.savefig("distfin.png")

# mostra grafico
plt.show()
##
