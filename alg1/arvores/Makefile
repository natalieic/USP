all: avl.o avl_main.o
	gcc avl.o avl_main.o -o main -std=c99 -Wall -Wextra

avl_main.o:
	gcc -c avl_main.c

avl.o:
	gcc -c avl.c

item.o:
	gcc -c ../item/item.c

rb_main.o:
	gcc -c rb_main.c

rbt.o:
	gcc -c ../projeto2/Sets/rbt.c

run:
	./main

clean:
	rm *.o rb

rb: rbt.o rb_main.o
	gcc rbt.o rb_main.o -o rb -std=c99 -Wall -Wextra
