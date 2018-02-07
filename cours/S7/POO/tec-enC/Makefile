LIB=tec

CC=gcc
CPPFLAGS=-I ${LIB}
CFLAGS=-std=c99 -W -Wall 
LDFLAGS=-L ${LIB}

all: simple

clean:
	rm -f simple

cleanall: clean
	cd ${LIB}; make cleanall

simple: simple.c ${LIB}/libtec.a
	$(CC) ${CPPFLAGS} ${CFLAGS} $(LDFLAGS) simple.c -ltec -o $@ 

${LIB}/libtec.a:
	cd ${LIB}; make

