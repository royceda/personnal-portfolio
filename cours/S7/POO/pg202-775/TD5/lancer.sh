javac -d build/ -cp build/ src/*.java recette/Simple.java &&
javac -d build-tst -cp build tst/*.java &&
java -ea -cp build-tst/:build/ tec.LancerTests &&
java -cp build/ Simple &&
rm -r build/* build-tst/*