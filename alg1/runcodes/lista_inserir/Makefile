all: item.o inserir.o
	gcc ../../item/item.o inserir.o -std=c99 -Wall

item.o:
	gcc -c ../../item/item.c -o ../../item/item.o

inserir.o:
	gcc -c inserir.c

clean:
	rm ../../item/item.o inserir.o