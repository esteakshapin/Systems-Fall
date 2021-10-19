all: main.o namegen.o
	gcc -o a.out main.o namegen.o

main.o: main.c namegen.h
	gcc -c main.c

namegen.o: namegen.c namegen.h
	gcc -c namegen.c

run:
	make && ./a.out

clean:
	rm a.out
	rm *.o
	rm *~