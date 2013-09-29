This is a C library that aims to provide useful functions for 
calculating neutrino oscialltion probabilities in two and three-
flavor frameworks. 

It is under construction and not fully functional (you can call the C code
directly, which may be enough for you, but more is coming).

To build:

* source the setup.sh script. On Max OSX this will update your LD_LIBRARY_PATH.
On Linux, it will update your LD_LIBRARY_PATH.

* Type make. This will run an architecture dependent make. Currently only `uname` equals Darwin and Linux is resolved.

To-do:

* Add an API for R code to call functions.

* Add an R script demoing some of the code.

