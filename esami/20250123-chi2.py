import numpy as np
import matplotlib.pyplot as plt
import math as m

# lettura dati
chi2, n = np.loadtxt("chi2.dat", unpack = True)

# calcolo dof dal valore massimo in n
dof = int((max(chi2)+1)/2)

plt.title("Distribuzione di $\chi^2$ con %2d gradi di liberta`"%(dof))

plt.plot(chi2, n, '-o', color='blue', label='conteggi')

plt.xlim(0, len(chi2)+1)
plt.ylim(0, max(n)*1.2)

plt.xlabel('$\chi^2(x)$')
plt.ylabel('numero conteggi')

plt.grid()
plt.legend(loc='upper center')
#plt.savefig('chi2.png')

plt.show()


