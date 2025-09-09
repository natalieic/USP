all: item.o pilha.o rpn.o
	gcc item.o pilha.o rpn.o -o rpn -std=c99 -Wall

item.o:
	gcc item.c -c

pilha.o:
	gcc pilha.c -c

run:
	./rpn

clean:
	rm *.o rpn