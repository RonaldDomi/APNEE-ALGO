CC=gcc

all: oracle generation

tableau.o: tableau.c tableau.h
	gcc -c tableau.c tableau.h

oracle.o: oracle.c tableau.h
	gcc -c oracle.c tableau.h

oracle: oracle.o tableau.o
	gcc -o oracle oracle.o tableau.o

generation.o: generation.c tableau.h
	gcc -c generation.c tableau.h

generation: generation.o tableau.o
	gcc -o generation generation.o tableau.o

clean:
	rm -r *.o *.h.gch oracle generation
