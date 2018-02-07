INCLUDE = ../include
LIBPATH = ../lib
CXX = g++
CXXFLAGS= -Wall -I${INCLUDE}
LDFLAGS = -L${LIBPATH} -lenseirb
SRCS =  Curseur.cpp CurseurClassique.cpp CurseurInverse.cpp CurseurPas.cpp prog.cpp
OBJS = $(subst .cpp,.o,${SRCS})
EXEC = test

${EXEC}: ${OBJS}
	${CXX} $^ -o ${EXEC} ${LDFLAGS}

.PHONY: all clean

-include .depends

.depends: ${SRCS}
	${CXX} -MM $(CXXFLAGS) $^ > .depends

all: {EXEC}

%.o : %.cpp
	${CXX} ${CXXFLAGS} -c $<

clean:
	rm -f *.o *.depends prog
