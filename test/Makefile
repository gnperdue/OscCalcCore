OSCLIBDIR=$(shell sh -c 'cd ../lib; pwd')
OSCINCDIR=$(shell sh -c 'cd ../OscCalc; pwd')

LDLIBS = -L$(OSCLIBDIR) -lOscCalc
INCLUDE = -I$(OSCINCDIR)

CC = clang

CFLAGS = 
LDFLAGS = 

all: test

test: OscCalcTester.o
	$(CC) $(LDFLAGS) -o test OscCalcTester.o $(LDLIBS)

OscCalcTester.o: OscCalcTester.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf *.dSYM/
	rm -f *.o
	rm test

remake:
	make clean
	make all
