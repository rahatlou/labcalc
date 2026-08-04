import matplotlib.pyplot as plt
import numpy as np

rho,flusso = np.loadtxt("traffico.dat", unpack=True)

    
plt.figure(figsize=(9, 6))
plt.plot(rho, flusso, marker='o', linewidth=2, markersize=8)

plt.xlabel('Densità veicolare ($\\rho$)')
plt.ylabel('Flusso ($J$)')
plt.title('Diagramma Fondamentale del Traffico (TASEP)')
plt.grid(True, linestyle='--', alpha=0.7)

plt.savefig('traffico.png', dpi=300)
print("Grafico salvato in soluzione_grafico.png")

plt.show()
