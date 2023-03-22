GHK & Nernst examples 
=====================

[![Continuous build using OMV](https://github.com/OpenSourceBrain/ghk-nernst/actions/workflows/omv-ci.yml/badge.svg)](https://github.com/OpenSourceBrain/ghk-nernst/actions/workflows/omv-ci.yml)

Sample [LEMS & NeuroML 2](https://github.com/OpenSourceBrain/ghk-nernst/tree/master/NeuroML2) files implementing a single compartment model, containing HH
type Na+/K+ channels, a Ca++ channel and pool. The Calcium current
through the channel can be calculated either through the [GHK flux
equation](http://en.wikipedia.org/wiki/GHK_flux_equation), or using
Ohm's law + [Nernst
Equation](http://en.wikipedia.org/wiki/Nernst_equation) to approximate
its reversal potential.

The same mechanisms are implemented in _NEURON_ as a comparison. Notice 
that _NEURON_ has built in support for calculating reversal potentials
via the Nernst equation, which can be compared to our implementation written from
scratch by running
[Native NEURON](https://github.com/OpenSourceBrain/ghk-nernst/blob/master/NEURON/nernstnat_na_k_ca.py), 
[from scratch](https://github.com/OpenSourceBrain/ghk-nernst/blob/master/NEURON/nernst_na_k_ca.py); see 
also [native Nernst modfile](https://github.com/OpenSourceBrain/ghk-nernst/blob/master/NEURON/cachan_nernst_native.mod) and 
[from scratch modfile](https://github.com/OpenSourceBrain/ghk-nernst/blob/master/NEURON/cachan_nernst.mod).


Running tests
-------------

The following tests can be run to compare the usage of  GHK/Nernst from  _NEURON_/_LEMS_:
   

    git clone git@github.com:OpenSourceBrain/ghk-nernst.git
    cd ghk-nernst/NEURON/
    nrnivmodl
    ./ghk_na_k_ca.py
    ./nernst_na_k_ca.py

    cd ../NeuroML2
    jnml LEMS_ghk_na_k_ca.xml
    jnml LEMS_nernst_na_k_ca.xml

    cd ../
    python compare.py
   

neuroConstruct
--------------

Recent versions of neuroConstruct support GHK, generating NeuroML2 and
NEURON code accordingly. In order to use the GHK flux equation instead
of Ohm's law for a particular mechanism, set an extra parameter
GHK_permeability (in m/s) using the *Edit Density Mechs* dialog.

![Image](./images/nc_ghk.png?raw=true)
 


Definitions
-----------

From [Wikipedia](http://en.wikipedia.org/wiki/GHK_flux_equation)                                                   

                                             concInt -  concExt * exp(-z * V * F /(R * T))                        
     Idensity = P * z^2 * V * F^2/(R * T)  - - - - - - - - - - - - - - - - - - - - - - - - - -                    
                                                     1 - exp(-z * V * F /(R * T))                                 


From Steuber et al DCN model:                                                                                

     A = exp(-23.20764929 * v / T) = exp((-z * F * (0.001) * v) / (R * T))                                        

     ical = perm * m*m * h * (4.47814e6 * v / T) * ((cali/1000) - (calo/1000) * A) / (1 - A)                      

     (z^2 * F^2 * (0.001) * v) / (R * T)                                                                          


From [GENESIS](http://www.genesis-sim.org/GENESIS/gum-tutorials/beeman/Hyperdoc/Manual-26.html#ss26.30)

              valency * F                                                                                          
     K     =  - - - - - - -                                                                                        
              R * (T + 273)                                                                                        

                               Cin * exp(K * Vm) - Cout                                                           
     Ik    =  -p * F * K * Vm  - - - - - - - - - - - -                                                            
                                   exp(K * Vm) - 1                                                                

     (it is  missing one valency factor in comparison to the others, check genesis source)

