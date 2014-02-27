#!/usr/bin/env sh

cd $HOME
mkdir neuron
cd neuron
hg clone http://www.neuron.yale.edu/hg/neuron/nrn
cd nrn
./build.sh
./configure --prefix=`pwd` --without-iv --with-nrnpython=`python -c 'import sys; print sys.executable'`
make
sudo make install

cd src/nrnpython
#python setup.py install --prefix=$HOME/local
sudo pip install -e .
cd $HOME


