import matplotlib.pyplot as plt
import numpy as np

# times in ms
def G(t, t0=0.4, sig=0.03, T=0.015):
  return np.exp(-(t-t0)**2/(2*sig**2)) * np.sin(2*np.pi*t/T)


t0= 0.4
sig=0.03
T = 0.015
times =np.linspace(t0, 4*t0, 2000)


plt.rcParams.update({'axes.labelsize': 16, 'xtick.labelsize': 14, 'ytick.labelsize': 14})

plt.figure(figsize=(10, 6))
plt.xscale('log')
plt.xlim(t0, 2*t0)
plt.xlabel('time (ms)',fontsize=16)
plt.ylabel('Ampiezza del segnale G(t)', fontsize=16)


plt.plot(times, G(times, t0, sig, T), label="G(t)")



plt.legend(fontsize=16)
plt.savefig("high_res_GW.png", dpi=300)
#plt.show()

def Period(t, period, tau=0.2): # times in ms 
  return period*np.exp(-t/tau)

def G2(t, t0=0.4, sigma=0.03, period=0.015):
  return np.exp(-(t-t0)**2/(2*sigma**2)) * np.sin(2*np.pi*t/Period(t,period,tau=0.2))

t0= 0.4
sig=0.03
T1 = 0.015
times =np.linspace(t0, 5*t0, 3000)

plt.figure(figsize=(10, 6))
plt.xscale('log')
plt.xlim(t0, 2*t0)
plt.xlabel('time (ms)',fontsize=16)
plt.ylabel('Ampiezza del segnale smorzato G(t)', fontsize=16)


plt.plot(times, G2(times, t0, sigma=sig, period=T1), label="G(t)")
plt.legend(fontsize=16)
plt.savefig("high_res_GW_2.png", dpi=300)

