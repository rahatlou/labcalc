# carica moduli pyplot e numpy di python
import matplotlib.pyplot as plt
import numpy as np

plt.title("Gitatta in funzione di theta")

# carica dati dal file
# x e` un array con i dati nella prima colonna (theta)
# y e` un array con i dati della seconda colonna (gittata)
x, y = np.loadtxt('dati.txt', unpack=True)

# crea grafica di y in funzione di x
plt.plot( x, y, 'o-', label='dati caricati dal file')

# specifica limite inferiore superiore per asse x e y
plt.xlim(0., 1.60)
plt.ylim(0., 250.)

# aggiungi legenda per gli assi
plt.xlabel('angolo theta (rad)')
plt.ylabel('gittata G (metri)')


# nome del file in cui salvare il grafico
plt.savefig("grafico.png")

# mostra grafico
plt.show()
