
simulation : tests.o Bacteria.o BacterieL.o
	g++ tests.o Bacteria.o BacterieL.o -o simulation

BacterieL.o : BacterieL.cpp BacterieL.h Bacteria.h
	g++ -c BacterieL.cpp -o BacterieL.o

Bacteria.o : Bacteria.cpp Bacteria.h
	g++ -c Bacteria.cpp -o Bacteria.o

tests.o : tests.cpp Bacteria.h BacterieL.h
	g++ -c tests.cpp -o tests.o
