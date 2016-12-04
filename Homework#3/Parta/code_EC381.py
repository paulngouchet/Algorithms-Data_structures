import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import math


from scipy.stats import binom
import matplotlib.pyplot as plt

## Plot for W 

## Binomial distribution 
fig, ax = plt.subplots(1, 1)
Calculate a few first moments:


n, p = 6, 1/6
 mean, var, skew, kurt = binom.stats(n, p, moments='mvsk')
Display the probability mass function (pmf):


 x = np.arange(binom.ppf(0.01, n, p),
...               binom.ppf(0.99, n, p))
ax.plot(x, binom.pmf(x, n, p), 'bo', ms=8, label='binom pmf')
ax.vlines(x, 0, binom.pmf(x, n, p), colors='b', lw=5, alpha=0.5)
Alternatively, freeze the distribution and display the frozen pmf:


rv = binom(n, p)
ax.vlines(x, 0, rv.pmf(x), colors='k', linestyles='-', lw=1,
...         label='frozen pmf')
ax.legend(loc='best', frameon=False)
plt.show()




## Gaussian distribution
mu = 1/6
variance = 5/36
sigma = math.sqrt(variance)
x = np.linspace(-3, 3, 100)
plt.plot(x,mlab.normpdf(x, mu, sigma))

plt.show()





## Plot for W 

## Binomial distribution 
fig, ax = plt.subplots(1, 1)
Calculate a few first moments:


n, p = 12, 1/6
 mean, var, skew, kurt = binom.stats(n, p, moments='mvsk')
Display the probability mass function (pmf):


 x = np.arange(binom.ppf(0.01, n, p),
...               binom.ppf(0.99, n, p))
ax.plot(x, binom.pmf(x, n, p), 'bo', ms=8, label='binom pmf')
ax.vlines(x, 0, binom.pmf(x, n, p), colors='b', lw=5, alpha=0.5)
Alternatively, freeze the distribution and display the frozen pmf:


rv = binom(n, p)
ax.vlines(x, 0, rv.pmf(x), colors='k', linestyles='-', lw=1,
...         label='frozen pmf')
ax.legend(loc='best', frameon=False)
plt.show()




## Gaussian distribution
mu = 1/6
variance = 5/36
sigma = math.sqrt(variance)
x = np.linspace(-3, 3, 100)
plt.plot(x,mlab.normpdf(x, mu, sigma))

plt.show()






## Plot for W 

## Binomial distribution 
fig, ax = plt.subplots(1, 1)
Calculate a few first moments:


n, p = 18, 1/6
 mean, var, skew, kurt = binom.stats(n, p, moments='mvsk')
Display the probability mass function (pmf):


 x = np.arange(binom.ppf(0.01, n, p),
...               binom.ppf(0.99, n, p))
ax.plot(x, binom.pmf(x, n, p), 'bo', ms=8, label='binom pmf')
ax.vlines(x, 0, binom.pmf(x, n, p), colors='b', lw=5, alpha=0.5)
Alternatively, freeze the distribution and display the frozen pmf:


rv = binom(n, p)
ax.vlines(x, 0, rv.pmf(x), colors='k', linestyles='-', lw=1,
...         label='frozen pmf')
ax.legend(loc='best', frameon=False)
plt.show()




## Gaussian distribution
mu = 1/6
variance = 5/36
sigma = math.sqrt(variance)
x = np.linspace(-3, 3, 100)
plt.plot(x,mlab.normpdf(x, mu, sigma))

plt.show()












