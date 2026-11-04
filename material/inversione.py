import numpy as np
import matplotlib.pyplot as plt

TAU = 2.5
t = np.linspace(0., 12., 300)
plt.plot(t, 1. - np.exp(-t / TAU), color='#14213D', linewidth=2, label='u = 1 - exp(-t / tau)')
for u, col in [(0.3, '#2A9D8F'), (0.8, '#E76F51')]:
    ts = -TAU * np.log(1. - u)
    plt.plot([0., ts], [u, u], '--', color=col)
    plt.plot([ts, ts], [u, 0.], '--', color=col)
    plt.plot(ts, u, 'o', color=col)
    plt.text(ts + 0.2, 0.04, 't = %.2f s' % ts, color=col, fontsize=12)
plt.xlim(0., 12.)
plt.ylim(0., 1.02)
plt.xlabel('tempo t (s)')
plt.ylabel('u = drand48()')
plt.title('Da u al tempo: si sale sulla curva')
plt.legend(loc='lower right')
plt.savefig('inversione.png')
plt.show()
