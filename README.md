ghk-nernst
==========

Sample lems files implementing a single compartment model, containg HH
type Na+/K+ channels, a Ca++ channel and pool. The Calcium current
through the channel can be calculated either through the [GHK flux
equation](http://en.wikipedia.org/wiki/GHK_flux_equation), or using
Ohm's law + [Nernst
Equation](http://en.wikipedia.org/wiki/Nernst_equation) to approximate
its reversal potential.

The same mechanisms are implemented in NEURON as a comparison. 
