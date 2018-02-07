LEX=lex
YACC=yacc
CFLAGS=-Wall
CC=gcc

compiler:frontend.c scanner_simple.c
	$(CC) $(CFLAGS) -o $@ $^

frontend.c:frontend.y
	$(YACC) -o $@ --defines=frontend.tab.h $^

%.c:%.l
	$(LEX) -o $@ $^

clean:
	rm -f frontend.c backend.c
