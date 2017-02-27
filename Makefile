
simulation : tests.o Bacteria.o
	g++ tests.o Bacteria.o -o simulation

Bacteria.o : Bacteria.cpp Bacteria.h
	g++ -c Bacteria.cpp -o Bacteria.o

tests.o : tests.cpp Bacteria.h
	g++ -c tests.cpp -o tests.o
