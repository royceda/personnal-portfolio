CXXFLAGS=-Wall

prog: Chaine.o Programme.o 
	g++ ${CXXFLAGS} $^ -o $@ -g

Programme.o: Chaine.hpp

clean:
	rm -f *.o prog
