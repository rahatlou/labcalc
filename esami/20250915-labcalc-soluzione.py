import numpy as np
import matplotlib.pyplot as plt

plt.title ("metodo di Metropolis-Hastings")
n, p, freq=np.loadtxt("frequency.dat", unpack=True)
plt.plot (n, p, "-", color="blue", label= "p(n)")
plt.plot (n, freq, ".--", color="red", label = "freq(n)")
plt.xlabel ('n')
plt.ylabel ('p(n) e freq(n)')
plt.legend ()
plt.savefig ('frequenza.png') 
plt.show ()
