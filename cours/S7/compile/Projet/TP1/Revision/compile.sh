#!/bin/bash

rm count;
flex monfile2.l;
gcc lex.yy.c -o count -lfl;
./count < monfile2.l;
