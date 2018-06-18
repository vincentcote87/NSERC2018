CXX =g++ -std=c++11
IFLAGS = -I /usr/local/include
LFLAGS = -L /usr/local/lib64
LINKFLAGS = -lprimesieve -lmpfr -lgmp
RPATH = -Wl,-rpath=/usr/local/lib64 
PROGRAM = main
C ?= na
F ?= 

.PHONY: all
main: clean
	$(CXX) $(IFLAGS) $(LFLAGS) main.cc -o $(PROGRAM) $(LINKFLAGS) $(RPATH)

static: clean
	$(CXX) $(IFLAGS) $(LFLAGS) main.cc -o $(PROGRAM) $(LINKFLAGS) $(RPATH) -static

condor: 
	condor_compile $(CXX) $(IFLAGS) $(LFLAGS) main.cc -o $(PROGRAM) $(LINKFLAGS) $(RPATH)

custom:
	$(CXX) $(IFLAGS) $(LFLAGS) $(C).cc -o $(C) $(LINKFLAGS) $(RPATH) $(F) -static

clean:
	rm -rf *.o *~ main
