import matplotlib.pyplot as plt
import numpy as np

# dati: una colonna del file = un array
x, y = np.loadtxt('grave.txt', unpack=True)

# il grafico: i dati sono solo punti
plt.plot(x, y, 'o', label='dati del programma in C')

# etichette, titolo, griglia (senza accenti)
plt.xlabel('tempo (s)')
plt.ylabel('quota (m)')
plt.title('Caduta di un grave')
plt.grid()

# un riferimento: linea orizzontale a y = 0, con il suo nome per la legenda
plt.axhline(y=0., color='red', linestyle='--', label='suolo')
plt.legend()   # dopo tutte le curve e le righe, altrimenti manca 'suolo'

# salvare PRIMA di mostrare
plt.savefig('grafico.png')
plt.show()
