CC=gcc

all: oracle generation

tableau.o: tableau.c tableau.h
	gcc -c $^

oracle.o: oracle.c tableau.h
	gcc -c $^

oracle: oracle.o tableau.o
	gcc -o $@ $^

generation.o: generation.c tableau.h
	gcc -c $^

generation: generation.o tableau.o
	gcc -o $@ $^

clean:
	rm -r *.o *.h.gch oracle generation
