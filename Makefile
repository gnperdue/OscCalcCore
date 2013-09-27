
ARCH = $(shell uname)

all:
	make -C OscCalc -f Makefile.$(ARCH)
	make -C test -f Makefile.$(ARCH)

clean:
	make clean -C OscCalc -f Makefile.$(ARCH)
	make clean -C test -f Makefile.$(ARCH)

