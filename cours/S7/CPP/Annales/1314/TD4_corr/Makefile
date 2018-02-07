INCLUDE = include
CXXFLAGS=-Wall -I${INCLUDE}

lib: Chaine.o SmartPointer.o
	ar cr lib/libenseirb.a $^
	rm *.o

%.o : src/%.cpp
	g++ ${CXXFLAGS} -o $@ -c $^

clean:
	rm -f *.o prog
