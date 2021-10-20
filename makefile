all: main.o namegen.o nodeList.o teacher.o
	gcc -o a.out main.o namegen.o nodeList.o teacher.o

main.o: main.c namegen.h nodeList.h teacher.h
	gcc -c main.c

nodeList.o: nodeList.c nodeList.h teacher.h
	gcc -c nodeList.c

teacher.o: teacher.c teacher.h
	gcc -c teacher.c

namegen.o: namegen.c namegen.h
	gcc -c namegen.c

run:
	make && ./a.out

clean:
	rm a.out
	rm *.o
	rm *~