import numpy as np
import matplotlib.pyplot as plt

# carica i dati dal file
# colonne: nSalti   nPartite
n_salti, frequenza = np.loadtxt("salti.txt", unpack=True)


# normalizzazione opzionale (frequenza relativa)
#frequenza = conteggi / np.sum(conteggi)

# grafico a barre
#plt.figure(figsize=(8,5))
#plt.bar(n_salti, frequenza, width=0.8, label="frequenza di salti consecutivi")
plt.bar(n_salti, frequenza, label="frequenza di salti consecutivi")

plt.xlabel("Numero di salti consecutivi riusciti")
plt.ylabel("Frequenza")
#plt.yscale('log')
plt.title("Distribuzione del numero di salti consecutivi\nprima della caduta")

plt.grid(alpha=0.3)
plt.legend()
plt.tight_layout()
plt.savefig("grafico.png")
plt.show()
