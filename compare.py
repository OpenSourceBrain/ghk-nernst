from pylab import plot, show, figure
from numpy import loadtxt


lems = {'ghk': loadtxt('/tmp/lems_ghk.dat'),
        'nernst' : loadtxt('/tmp/lems_nernst.dat')}

nrn = {'ghk': loadtxt('/tmp/nrn_ghk.dat'),
       'nernst': loadtxt('/tmp/nrn_nernst.dat')}


for mod in ('ghk', 'nernst'):
    tlems, vlems, ilems, calems = lems[mod].T 
    tnrn, vnrn, inrn, canrn = nrn[mod].T 

    figure(mod + ': V_m')
    plot(tlems * 1000, vlems * 1000, '-r', label='lems')
    plot(tnrn, vnrn, '-b', label='neuron')

    figure(mod + ': I_Ca')
    plot(tlems * 1000, -0.1 * ilems, '-r', label='lems')
    plot(tnrn, inrn, '-b', label='neuron')

    figure(mod + ': [Ca]_i')
    plot(tlems * 1000, calems, '-r', label='lems')
    plot(tnrn, canrn, '-b', label='neuron')
    
show()
