# carica moduli pyplot, numpy e matematica di python
import matplotlib.pyplot as plt
import numpy as np
import math as m

plt.title("Calcolo della radice quadrata con il metodo babilonese")

# carica dati dal file
# iter e` un array con i dati nella prima colonna (theta)
# stima e` un array con i dati della seconda colonna (gittata)
iter, stima = np.loadtxt('dati.txt', unpack=True)

# crea grafica di stima in funzione di iter
plt.plot( iter, stima, 'x-', label='stima con il metodo babilonese')

# specifica limite inferiore superiore per asse x e y con
# numeri opportuni in base ai vostri dati
# per esempio se state stimando la radice di a = 15 con circa 5 iterazioni
plt.xlim(0, 10)
plt.ylim(3., 5.)

# aggiungi legenda per gli assi
plt.xlabel('numero iterazione')
plt.ylabel('stima radice a')

# linea orizzontale rossa al valore di sqrt(a) usando la libreria matematica
plt.axhline( y=m.sqrt(15), color = 'red', linestyle='--')

# nome del file in cui salvare il grafico
plt.savefig("radice.png")

# mostra grafico
plt.show()
