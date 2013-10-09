#!/usr/bin/ipython -i

from neuron import *
from nrn import *
#from neuron import gui


h.celsius = 16.3

def create_comp(name = 'soma'):
    
    h('create ' + name)
    comp = h.__getattribute__(name)

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

    h('cao0_ca_ion = 2')
    h('cai0_ca_ion = 3e-6')
    h('nao = 115')
    h('nai = 15')

    h.ion_style("na_ion", 1, 2, 1, 0, 0) 

    return comp


def create_nrn_graphs(name):
    g_v = h.Graph()
    g_v.size(0,5,-80,40)
    h.graphList[0].append(g_v)
    g_v.addexpr(name + '.v(0.5)', 1, 1, 0.8, 0.9, 2)

    g_ica = h.Graph()
    g_ica.size(0,5,-0.04,0.02)
    h.graphList[0].append(g_ica)
    g_ica.addexpr(name + ".ica", 1, 1, 0.49214, 0.971132, 2)
    g_ica.addexpr(name + ".ica_cachanghk", 4, 1, 2.50949, 0.00180314, 1)

    g_ca = h.Graph()
    g_ca.size(0,5,0,0.5e-4)
    h.graphList[0].append(g_ca)
    g_ca.addexpr(name + ".cai", 2, 1, 0.367087, 0.966017, 2)

    #g_na = h.Graph()
    #g_na.size(0,5,0,20)
    #h.graphList[0].append(g_na)
    #g_na.addexpr(name + ".nai", 2, 1, 0.367087, 0.966017, 2)
    
def plot_timeseries(varlist):
    from pylab import plot, show, figure
    from numpy import savetxt

    v = get_dumps(varlist)
    savetxt('/tmp/nrnghk.dat', v)
    for i in range(1, v.shape[1]):
        figure()
        plot(v[:,0], v[:,i])
    show()
    

    
def create_dumps(secname, varlist):
    h('objref t_vec')
    h('t_vec = new Vector()')
    h('t_vec.record(&t)')

    for vv in varlist:
        v = vv[:vv.index('(')] + '_vec' 
        h('objref ' + v)
        h(v + " = new Vector()")
        h(v + '.record(&' + secname + '.' + vv + ')')
        
        
def get_dumps(varlist):
    from numpy import c_
    pvs = [h.t_vec.to_python()]
    for vv in varlist:
        v = vv[:vv.index('(')] + '_vec' 
        pvs.append(h.__getattribute__(v).to_python())
    return c_[pvs[:]].T

def run(tstop=10, dt=0.001):
    h.dt = dt
    h.finitialize(-65)
    h.fcurrent()
    h.frecord_init()
    while h.t < tstop:
        h.fadvance()



comp = create_comp('soma')
name = comp.name()

stim = h.IClamp(0.5, sec=comp)
stim.delay = 4
stim.dur = 0.1
stim.amp = 0.05

varlist = ['v(0.5)', 'ica(0.5)', 'cai(0.5)']
#create_nrn_graphs(name)
create_dumps(name, varlist)
run(20, 0.001)

plot_timeseries(varlist)