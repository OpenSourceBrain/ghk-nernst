#!/usr/bin/env sh

mkdir neuron
cd neuron
hg clone http://www.neuron.yale.edu/hg/neuron/nrn
cd nrn
./build.sh
./configure --prefix=`pwd` --without-iv --with-nrnpython=`python -c 'import sys; print sys.executable'`
make
make install

cd src/nrnpython
sudo python setup.py install

