#!/usr/bin/ipython -i

from neuron import *
from nrn import *
#from neuron import gui



def create_comp(name = 'soma'):
    
    comp = h.Section('soma')

    comp.insert('HHna')
    comp.insert('HHk')
    comp.insert('cachannernst')
    comp.insert('cabuff')
    comp.insert('pas')

    comp.nseg = 1
    comp.L = 10
    comp.diam = 1
    
    comp(0.5).g_pas = 0.0003
    comp(0.5).e_pas = -53.1

    pcabar = 2.5e-5
    comp(0.5).cachannernst.pcabar = pcabar
    #comp(0.5).HHna.gnabar = .120
    #comp(0.5).HHk.gkbar = .036
    comp(0.5).HHna.gnabar = 0.0
    comp(0.5).HHk.gkbar = 0.0
    
    #phi will be multiplied by ica _density_
    area = h.area(0.5)
    phi = 3e-3
    #phi = 0
    print 'phi times area to be used in lems', phi * area
    comp(0.5).cabuff.phi = phi


    h.cao0_ca_ion = 2
    #.cai0_ca_ion = 3e-6
    h.cai0_ca_ion = 5e-6
    h('nao = 115')
    h('nai = 15')

    h.celsius = 16.3
    
    #we don't need nrn to calculate the nernst potential for ca
    h.ion_style("ca_ion", 3, 0, 0, 0, 1) 

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


def dump_to_file(vdict, varlist, fname='/tmp/nrn_nernst.dat'):
    from numpy import savetxt, array

    vnames = ['t'] + varlist
    X = array([vdict[x].to_python() for x in vnames]).T
    savetxt(fname, X)


def run(tstop=10, dt=0.001):
    h.dt = dt
    h.finitialize(-65)
    h.fcurrent()
    h.frecord_init()
    while h.t < tstop:
        h.fadvance()



comp = create_comp('soma')

# stim = h.IClamp(0.5, sec=comp)
# stim.delay = 4
# stim.dur = 0.1
# stim.amp = 0.05


varlist = ['v', 'ica', 'cai', 'cao', 'eca', 'oca_cachannernst']
ds = create_dumps(comp, varlist)

run(50, 0.001)

plot_timeseries(ds, varlist)
dump_to_file(ds, varlist)