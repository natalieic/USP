all: ponto.o circulo.o main.o
	gcc ponto.o circulo.o main.o -o main -std=c99 -Wall

ponto:
	gcc -c ponto.c -o ponto.o

circulo:
	gcc -c circulo.c -o circulo.o

main:
	gcc -c main.c -o main.o

run:
	./main

clean:
	rm *.o main