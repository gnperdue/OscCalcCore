This is a C library that aims to provide useful functions for 
calculating neutrino oscialltion probabilities in two and three-
flavor frameworks. 

It currently builds on Mac OSX only, but fairly trivial adaptions to 
the Makefiles and setup scripts will enable the code to build on 
most Linux distributions as well.

To build:

* source the setup.sh script. On Max OSX this will update your LD_LIBRARY_PATH.
On Linux, it will update your LD_LIBRARY_PATH.

* Type make. This will run an architecture dependent make. Currently only `uname` equals Darwin is resolved.

