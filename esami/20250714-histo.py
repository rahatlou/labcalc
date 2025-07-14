import numpy as np
import matplotlib.pyplot as plt

bin, istoA, istoB = np.loadtxt('isto.dat', unpack=True)

plt.title("Distribuzione di $\epsilon$ per due metodi di risoluzione di eq di secondo grado");
plt.xlabel('(int)$log_{10}(\epsilon)$+BINS')
plt.ylabel('frequenza')

plt.plot(bin, istoA, 'b', label="metodo A: comunemente usato" )
plt.plot(bin, istoB, 'r--', label="metodo B: preciso numericamente")
plt.legend()

plt.show()

