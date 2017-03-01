
simulation : tests.o Bacteria.o BacterieL.o BacterieS.o
	g++ tests.o Bacteria.o BacterieL.o BacterieS.o -o simulation

BacterieS.o : BacterieS.cpp BacterieS.h Bacteria.h
	g++ -c BacterieS.cpp -o BacterieS.o

BacterieL.o : BacterieL.cpp BacterieL.h Bacteria.h
	g++ -c BacterieL.cpp -o BacterieL.o

Bacteria.o : Bacteria.cpp Bacteria.h
	g++ -c Bacteria.cpp -o Bacteria.o

tests.o : tests.cpp Bacteria.h BacterieL.h BacterieS.h
	g++ -c tests.cpp -o tests.o
