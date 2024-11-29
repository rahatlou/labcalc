# carica moduli pyplot, numpy e matematica di python
import matplotlib.pyplot as plt
import numpy as np
import math as m

##
####  istogramma della distribuzione num simulazioni in funzion della posizione finale
##
pos, freq = np.loadtxt('frequenza.txt', unpack=True)

plt.title("Distribuzione posizioni finali con $N_{passi} = 20$")

# istogramma dei valori letti dal file
plt.bar( pos, height=freq, label='')

plt.xlabel("coordinata posizione finale")
plt.ylabel("# simulazioni")

# linea vertical a x = 0
plt.axvline( x=0., color = 'red', linestyle='dotted')

plt.show()



