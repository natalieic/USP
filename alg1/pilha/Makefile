all: item.o pilha.o main.o
	gcc item.o pilha.o main.o -o main -std=c99 -Wall

item.o:
	gcc -c ../item/item.c

pilha.o:
	gcc -c pilha.c

main.o:
	gcc -c main.c

run: all
	./main

clean:
	rm *.o main
