all: cbuild cbuild-tst lancer lancer-tst

cbuild:	
	javac -d build/ -cp build/ src/*.java recette/Simple.java

lancer: build
	java -cp build/ Simple

cbuild-tst:		
	javac -d build-tst -cp build tst/*.java

lancer-tst: build-tst
	java -ea -cp build-tst/:build/ tec.LancerTests

.PHONY: clean

clean: 	
	rm -r build/* build-tst/*
