
all: main.o
	gcc -o a.out main.o -lSDL2main -lSDL2 -lSDL2_ttf

main.o: main.c
	gcc -c main.c

run:
	make && ./a.out

clean:
	rm a.out
	rm *.o
	rm *~