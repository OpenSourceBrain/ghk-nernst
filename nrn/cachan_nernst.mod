TITLE CaChan
: Calcium Channel with Nernst permeability
: The fraction of open calcium channels has the same kinetics as
:   the HH m process but is slower by taufactor

UNITS {
	(molar) = (1/liter)
}

UNITS {
	(mV) =	(millivolt)
	(mA) =	(milliamp)
	(mM) =	(millimolar)
}

NEURON {
	SUFFIX cachannernst
	USEION ca READ eca WRITE ica
	RANGE pcabar, ica
}

UNITS {
	:FARADAY = 96520 (coul)
	:R = 8.3134 (joule/degC)
	:boris: bypass neuron's faraday const
	: FARADAY = (faraday) (coulomb)
	FARADAY = (96485.3) (coulomb)
	R = (k-mole) (joule/degC)
}

PARAMETER {
	taufactor=2	<1e-6, 1e6>: Time constant factor relative to standard HH
	pcabar=.2e-7	(cm/s)	<0, 1e9>: Maximum Permeability
}

ASSIGNED {
	celsius		(degC)
	v		(mV)
	:cai		(mM)
	:cao		(mM)
	eca             (mV)
	ica		(mA/cm2)
}

STATE {	oca }		: fraction of open channels

INITIAL {
	oca = oca_ss(v)
}

BREAKPOINT {
	SOLVE castate METHOD cnexp
	:ica = pcabar*oca*oca*(v - nernst(cai, cao))
	ica = pcabar*oca*oca*(v - eca)
}

DERIVATIVE castate {
	LOCAL inf, tau
	inf = oca_ss(v)  tau = oca_tau(v)
	oca' = (inf - oca)/tau
}

FUNCTION nernst(ci(mM), co(mM)) (mV) {
        LOCAL z
	z = R*(celsius+273.15)/(2*FARADAY)
	nernst = z * log(ci/co)
}

FUNCTION efun(z) {
	if (fabs(z) < 1e-4) {
		efun = 1 - z/2
	}else{
		efun = z/(exp(z) - 1)
	}
}

FUNCTION oca_ss(v(mV)) {
	LOCAL a, b
	:TABLE FROM -150 TO 150 WITH 200
	
	v = v+65
	a = 1(1/ms)*efun(.1(1/mV)*(25-v))
	b = 4(1/ms)*exp(-v/18(mV))
	oca_ss = a/(a + b)
}

FUNCTION oca_tau(v(mV)) (ms) {
	LOCAL a, b, q
	:TABLE DEPEND celsius, taufactor FROM -150 TO 150 WITH 200

	q = 3^((celsius - 6.3)/10 (degC))
	v = v+65
	a = 1(1/ms)*efun(.1(1/mV)*(25-v))
	b = 4(1/ms)*exp(-v/18(mV))
	oca_tau = taufactor/(a + b)
}

