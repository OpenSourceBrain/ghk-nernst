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



From [GENESIS](http://www.genesis-sim.org/GENESIS/gum-tutorials/beeman/Hyperdoc/Manual-26.html#ss26.30)

	      valency * F                                                                                          
     K     =  - - - - - - -                                                                                        
	      R * (T + 273)                                                                                        

			       Cin * exp(K * Vm) - Cout                                                           
     Ik    =  -p * F * K * Vm  - - - - - - - - - - - -                                                            
				   exp(K * Vm) - 1                                                                

     (it is  missing one valency factor in comparison to the others, check genesis source)


From Steuber et al DCN model:                                                                                

     A = exp(-23.20764929 * v / T) = exp((-z * F * (0.001) * v) / (R * T))                                        

     ical = perm * m*m * h * (4.47814e6 * v / T) * ((cali/1000) - (calo/1000) * A) / (1 - A)                      

     (z^2 * F^2 * (0.001) * v) / (R * T)                                                                          

From [Wikipedia](http://en.wikipedia.org/wiki/GHK_flux_equation)                                                   

					     concInt -  concExt * exp(-z * V * F /(R * T))                        
     Idensity = P * z^2 * V * F^2/(R * T)  - - - - - - - - - - - - - - - - - - - - - - - - - -                    
						     1 - exp(-z * V * F /(R * T))                                 
