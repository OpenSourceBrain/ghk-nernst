#!/usr/bin/ipython -i

from neuron import *
from nrn import *
from neuron import gui


h.celsius = 16.3

def create_comp():
    
    comp = Section()

    comp.insert('HHna')
    comp.insert('HHk')
    comp.insert('cachan')
    comp.insert('cadifpmp')
    comp.insert('nacax')
    comp.insert('capump')
    comp.insert('pas')

    comp.nseg = 1
    comp.L = 10
    comp.diam = 1
    
    comp(0.5).g_pas = 0.0003
    comp(0.5).e_pas = -53.1

    h('k1_cadifpmp = 30e8')
    h('k2_cadifpmp = .25e6')
    h('k3_cadifpmp = 1.5e3')
    h('k4_cadifpmp = 5e0')
    h('pump0_cadifpmp = 1e-13')
    h('beta_cadifpmp = 100')
    h('kmp_capump = 0.2  ')
    h('vmax_capump = .0667*0')
    h('pcabar_cachan = 2.5e-5')
    h('gnabar_HHna = .120')
    h('gkbar_HHk = .036')
    h('k_nacax = .00015')

    h('cao0_ca_ion = 2')
    h('cai0_ca_ion = 3e-6')
    h('nao = 115')
    h('nai = 15')

    h.ion_style("na_ion", 1, 2, 1, 0, 0) 

    return comp


comp = create_comp()
stim = h.IClamp(0.5, sec=comp)
stim.delay = 0
stim.dur = 0.1
stim.amp = 0.05



g = h.Graph(0)
g.size(0,5,-80,40)
h.graphList[0].append(g)
g.view(0, -80, 5, 120, 66, 52, 300.48, 200.32)
g.addexpr("v(.5)", 1, 1, 0.8, 0.9, 2)
