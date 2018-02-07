CXXFLAGS=-Wall

all: prog

prog: Chaine.o Programme.o 
	g++ ${CXXFLAGS} $^ -g -o $@

Programme.o: Chaine.hpp

clean:
	rm -f *.o prog
