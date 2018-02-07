CC=gcc
CFLAGS=-std=c99 -W -Wall 

OBJ=autobus.o ps_standard.o

all: lib 

obj: ${OBJ}

lib: libtec.a

libs: libtec.so

clean:
	rm -f *.o

cleanall: clean
	rm -f *.a *.so

autobus.o: autobus.c autobus.h __fonctions_internes.h

ps_standard.o: ps_standard.c ps_standard.h __fonctions_internes.h

libtec.a: ${OBJ}
	ar -r $@ ${OBJ}

libtec.so : ${OBJ}
	$(CC) -o $@ -shared ${OBJ}

