all: item.o encadeada.o main.o
	gcc item.o encadeada.o main_encadeada.o -o main -std=c99 -Wall

item.o:
	gcc -c ../item/item.c

encadeada.o:
	gcc -c encadeada.c

main.o:
	gcc -c main_encadeada.c

run: all
	./main

clean:
	rm *.o main