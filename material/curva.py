import numpy as np
import matplotlib.pyplot as plt

TAU = 2.5
t = np.linspace(0., 12., 300)
f = np.exp(-t / TAU) / TAU

plt.fill_between(t, f, color='#2A9D8F', alpha=0.35)
plt.plot(t, f, color='#14213D', linewidth=2)
plt.axvline(x=TAU, color='#E76F51', linestyle='--')
plt.text(TAU + 0.2, 0.30, 'tau', color='#E76F51', fontsize=14)
plt.xlim(0., 12.)
plt.ylim(0., 0.45)
plt.xlabel('tempo di attesa (s)')
plt.ylabel('quanti eventi')
plt.title('Tanti tempi brevi, pochi molto lunghi')
plt.savefig('curva.png')
plt.show()
