all: euler.o main.o
	gcc -o euler main.o euler.o

euler.o: euler.c euler.h
	gcc -c euler.c

main.o: main.c euler.h
	gcc -c main.c