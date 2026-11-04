import numpy as np
import matplotlib.pyplot as plt

TAU = 2.5
t = np.loadtxt('arrivi.txt')

plt.hist(t, bins=40, range=(0., 15.), density=True, label='dati')
tt = np.linspace(0., 15., 200)
f = np.exp(-tt / TAU) / TAU
plt.plot(tt, f, 'r-', label='formula')
plt.xlim(0., 15.)
plt.xlabel('tempo di attesa (s)')
plt.ylabel('densita')
plt.title('100000 attese, tau = 2.5 s')
plt.legend()
plt.savefig('esponenziale.png')
plt.show()
