#
#  -1 pt: titolo assi, etichetta e legenda errati
#  -1 pt: mancato salvataggio png
#  -2 pt: assenza di dati per provare il codice python
#
#  python viene valutato solo se viene correttamente creato il file
#  di dati necessario per eseguire python
#
import numpy as np
import matplotlib.pyplot as plt
import math as m

# lettura dati
E0, p = np.loadtxt("elettroni.txt", unpack = True)


plt.title("Percentuale di elettroni diffusi in avanti in funzione dell\'energia")

plt.plot(E0, p*100, '--', color='blue', label='percentuale')

plt.xlabel('$E_0$ [GeV]')
plt.ylabel('percentuale (%) elettroni in avanti')

plt.grid()
plt.legend(loc='upper left')
plt.savefig('diffusione.png')

plt.show()


