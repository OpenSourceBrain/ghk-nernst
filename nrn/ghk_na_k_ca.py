#!/usr/bin/ipython -i

from neuron import *
from nrn import *
#from neuron import gui


h.celsius = 16.3

def create_comp(name = 'soma'):
    
    comp = h.Section('soma')

    comp.insert('HHna')
    comp.insert('HHk')
    comp.insert('cachanghk')
    comp.insert('cabuff')
    comp.insert('pas')

    comp.nseg = 1
    comp.L = 10
    comp.diam = 1
    
    comp(0.5).g_pas = 0.0003
    comp(0.5).e_pas = -53.1

    comp(0.5).cachanghk.pcabar = 2.5e-5
    comp(0.5).HHna.gnabar = .120
    comp(0.5).HHk.gkbar = .036
    
    #phi will be multiplied by ica _density_
    area = h.area(0.5)
    phi = 3e-3
    print 'phi times area to be used in lems', phi * area
    comp(0.5).cabuff.phi = phi

    h.cao0_ca_ion = 2
    h.cai0_ca_ion = 3e-6
    h('nao = 115')
    h('nai = 15')

    h.ion_style("na_ion", 1, 2, 1, 0, 0) 

    return comp

    
def plot_timeseries(vdict, varlist):
    from pylab import plot, show, figure, title

    t = vdict['t']
    for n in varlist:
        figure()
        plot(t, vdict[n], label=n)
        title(n)
    
    show()

def create_dumps(section, varlist):
    recordings = {n: h.Vector() for n in varlist}

    for (vn, v) in recordings.iteritems():
        v.record(section(0.5).__getattribute__('_ref_' + vn))
    
    recordings['t'] = h.Vector()
    recordings['t'].record(h._ref_t)

    return recordings


def run(tstop=10, dt=0.001):
    h.dt = dt
    h.finitialize(-65)
    h.fcurrent()
    h.frecord_init()
    while h.t < tstop:
        h.fadvance()



comp = create_comp('soma')

stim = h.IClamp(0.5, sec=comp)
stim.delay = 4
stim.dur = 0.1
stim.amp = 0.05

varlist = ['v', 'ica', 'cai']
ds = create_dumps(comp, varlist)

run(20, 0.001)

plot_timeseries(ds, varlist)