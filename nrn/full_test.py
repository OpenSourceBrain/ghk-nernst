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


def create_graphs():
    g_v = h.Graph()
    g_v.size(0,5,-80,40)
    h.graphList[0].append(g_v)
    g_v.addexpr('v(0.5)', 1, 1, 0.8, 0.9, 2)

    g_ica = h.Graph()
    g_ica.size(0,5,-0.04,0.02)
    h.graphList[0].append(g_ica)
    g_ica.addexpr("ica", 1, 1, 0.49214, 0.971132, 2)
    g_ica.addexpr("ica_nacax", 2, 1, 0.496598, 0.980711, 2)
    g_ica.addexpr("ica_capump", 3, 1, 0.50973, 0.692392, 2)
    g_ica.addexpr("ica_cachan", 4, 1, 2.50949, 0.00180314, 1)
    g_ica.addexpr("ica_pmp_cadifpmp", 5, 1, 2.44857, 0.0350366, 1)

    g_ca = h.Graph()
    g_ca.size(0,5,0,0.5)
    h.graphList[0].append(g_ca)
    g_ca.addexpr("cai*1e4", 2, 1, 0.367087, 0.966017, 2)
    g_ca.addexpr("ca_cadifpmp[5]*1e4", 1, 1, 0.367089, 0.876387, 2)
    g_ca.addexpr("ca_cadifpmp[2]*1e4", 3, 1, 0.366456, 1.03701, 2)
    




comp = create_comp()

stim = h.IClamp(0.5, sec=comp)
stim.delay = 0
stim.dur = 0.1
stim.amp = 0.05

create_graphs()
h.run()