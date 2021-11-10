all: main.o namegen.o nodeList.o song.o musicLibrary.o
	gcc -o a.out main.o namegen.o nodeList.o song.o musicLibrary.o

main.o: main.c namegen.h nodeList.h musicLibrary.h
	gcc -c main.c

nodeList.o: nodeList.c nodeList.h
	gcc -c nodeList.c

namegen.o: namegen.c namegen.h
	gcc -c namegen.c

song.o: song.c song.h
	gcc -c song.c

musicLibrary.o: musicLibrary.c musicLibrary.h
	gcc -c musicLibrary.c

run:
	make && ./a.out

clean:
	rm a.out
	rm *.o
	rm *~