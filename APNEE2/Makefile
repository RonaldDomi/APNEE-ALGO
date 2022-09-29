CC=gcc

all: oracle

tableau.o: tableau.c tableau.h
	gcc -c tableau.c tableau.h

oracle.o: oracle.c tableau.h
	gcc -c oracle.c tableau.h

oracle: oracle.o tableau.o
	gcc -o oracle oracle.o tableau.o

clean:
	rm -r *.o *.h.gch oracle
