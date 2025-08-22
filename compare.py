from matplotlib import pyplot as plt
from numpy import loadtxt


lems = {
    "ghk": loadtxt("NeuroML2/lems_ghk.dat"),
    "nernst": loadtxt("NeuroML2/lems_nernst.dat"),
}

nrn = {"ghk": loadtxt("NEURON/nrn_ghk.dat"), "nernst": loadtxt("NEURON/nrn_nernst.dat")}


for mod in ("ghk", "nernst"):
    tlems, vlems, ilems, calems = lems[mod].T
    tnrn, vnrn, inrn, canrn = nrn[mod].T

    plt.figure(mod + ": V_m")
    plt.plot(tlems * 1000, vlems * 1000, "-r", label="lems")
    plt.plot(tnrn, vnrn, "-b", label="neuron")

    plt.figure(mod + ": I_Ca")
    plt.plot(tlems * 1000, -0.1 * ilems, "-r", label="lems")
    plt.plot(tnrn, inrn, "-b", label="neuron")

    plt.figure(mod + ": [Ca]_i")
    plt.plot(tlems * 1000, calems, "-r", label="lems")
    plt.plot(tnrn, canrn, "-b", label="neuron")

plt.show()
