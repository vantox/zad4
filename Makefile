CXX=g++
CXXFLAGS= -Wall -O2 -std=c++11

all: test

test: holding.hh test.cc
	$(CXX) $(CXXFLAGS) test.cc -o test

clean:
	rm test