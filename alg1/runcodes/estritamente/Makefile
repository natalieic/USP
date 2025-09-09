all: item.o ab.o main.o
	gcc item.o ab.o main.o -o main -std=c99 -Wall -Wextra

item.o:
	gcc -c item.c

ab.o:
	gcc -c ab.c

main.o:
	gcc -c main.c

run:
	./main

clean:
	rm *.o main

zip:
	zip aeb.zip Makefile ab* item* main.c