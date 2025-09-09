all: ../../item/item.o fila.o main.o
	gcc ../../item/item.o fila.o main.o -o main -std=c99 -Wall

item.o: 
	gcc -c ../../item/item.c

fila.o:
	gcc -c fila.c

main.o: 
	gcc -c main.c

run: all
	./main

clean:
	rm *.o main