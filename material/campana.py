import numpy as np
import matplotlib.pyplot as plt

MU = 25.00
SIGMA = 0.04
x = np.linspace(MU - 4. * SIGMA, MU + 4. * SIGMA, 400)
f = np.exp(-(x - MU)**2 / (2. * SIGMA**2)) / (SIGMA * np.sqrt(2. * np.pi))

plt.fill_between(x, f, where=abs(x - MU) < 2. * SIGMA, color='#FCA311', alpha=0.45)
plt.fill_between(x, f, where=abs(x - MU) < SIGMA, color='#E76F51', alpha=0.6)
plt.plot(x, f, color='#14213D', linewidth=2)
plt.text(MU, 3., '68%', ha='center', fontsize=16, color='white')
plt.text(MU + 1.55 * SIGMA, 1.2, '95%', ha='center', fontsize=14, color='#14213D')
plt.xticks([MU - 2 * SIGMA, MU - SIGMA, MU, MU + SIGMA, MU + 2 * SIGMA], ['μ-2σ', 'μ-σ', 'μ', 'μ+σ', 'μ+2σ'], fontsize=12)
plt.xlabel('misura')
plt.ylabel('densita')
plt.title('Misure ripetute attorno al valore vero')
plt.savefig('campana.png')
plt.show()
