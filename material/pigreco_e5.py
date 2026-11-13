# Esercitazione 5, Parte 2: le stime di pi e il loro istogramma.
# Si esegue dopo buffon_exp.exe, che scrive pigreco.txt (numero dell'esperimento e stima).
import numpy as np
import matplotlib.pyplot as plt

n, pi = np.loadtxt('pigreco.txt', unpack=True)     # una colonna del file, un array

# prima figura: le stime in funzione del numero dell'esperimento
plt.plot(n, pi, 'o', label='stime di pi')
plt.axhline(y=np.pi, color='red', linestyle='--', label='pi greco')
plt.xlabel('esperimento')
plt.ylabel('pi stimato')
plt.title('Le stime di pi')
plt.grid()
plt.legend()
plt.savefig('stime.png')      # prima di show
plt.show()

# il valore medio delle stime, calcolato con un ciclo come in C
media = 0
for i in range(len(pi)):
    media += pi[i]
media /= len(pi)

# seconda figura: l'istogramma delle stime
plt.hist(pi, bins=15, color='green')
plt.axvline(x=np.pi, color='red', linestyle='--', label='pi greco')
plt.axvline(x=media, color='blue', label='media delle stime')
plt.xlabel('pi stimato')
plt.ylabel('numero di esperimenti')
plt.title('La distribuzione delle stime di pi')
plt.legend()
plt.savefig('istogramma.png')
plt.show()
