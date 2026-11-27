# Esercitazione 7: due grafici, la caduta di una volta (grani.txt) e le NRIP cadute (conteggi.txt).
# Si esegue dopo masterchef.exe.
import numpy as np
import matplotlib.pyplot as plt

# Grafico 1: posizione dei grani, colorati per mattonella (0 = A, 1 = B, 2 = C, 3 = fuori)
x, y, k = np.loadtxt('grani.txt', unpack=True)

plt.scatter(x, y, c=k, s=8)
plt.axis('equal')
plt.xlabel('x (m)')
plt.ylabel('y (m)')
plt.title('Grani di sale sul pavimento')
plt.grid()
plt.savefig('grani.png')

# Grafico 2: istogrammi dei grani caduti in A, B e C nelle NRIP cadute
plt.figure()
NA, NB, NC = np.loadtxt('conteggi.txt', unpack=True)

plt.hist(NA, bins=20, alpha=0.6, label='mattonella A')
plt.hist(NB, bins=20, alpha=0.6, label='mattonella B')
plt.hist(NC, bins=20, alpha=0.6, label='mattonella C')
plt.xlabel('numero di grani nella mattonella')
plt.ylabel('numero di cadute')
plt.title('Grani per mattonella in 1000 cadute')
plt.grid()
plt.legend()
plt.savefig('conteggi.png')

plt.show()
