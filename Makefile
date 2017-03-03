
simulation : tests.o Bacteria.o BacterieL.o BacterieS.o
	g++ -std=c++11 tests.o Bacteria.o BacterieL.o BacterieS.o -o simulation

BacterieS.o : BacterieS.cpp BacterieS.h Bacteria.h
	g++ -c -std=c++11 BacterieS.cpp -o BacterieS.o

BacterieL.o : BacterieL.cpp BacterieL.h Bacteria.h
	g++ -c -std=c++11 BacterieL.cpp -o BacterieL.o

Bacteria.o : Bacteria.cpp Bacteria.h
	g++ -c -std=c++11 Bacteria.cpp -o Bacteria.o

tests.o : tests.cpp Bacteria.h BacterieL.h BacterieS.h
	g++ -c -std=c++11 tests.cpp -o tests.o
