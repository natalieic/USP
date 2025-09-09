all: item.o Deque.o main.o
	gcc item.o Deque.o main.o -o main -std=c99 -Wall

run: all
	./main

clean:
	rm *.o main