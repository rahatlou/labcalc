import matplotlib.pyplot as plt
import numpy as np

t, y = np.loadtxt('grave.txt', unpack=True)

plt.plot(t, y, 'o', color='teal', label='caduta da 20 m')
plt.xlabel('tempo (s)')
plt.ylabel('quota (m)')
plt.xlim(0., 2.5)
plt.ylim(-5., 22.)
plt.axhline(y=0., color='red', linestyle='--', label='suolo')
plt.axvline(x=np.sqrt(2. * 20. / 9.81), color='gray', linestyle=':', label='tempo di caduta')
plt.legend()
plt.grid()

plt.savefig('grave.png', dpi=150)   # prima di show!
plt.show()
