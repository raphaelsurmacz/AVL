CFLAGS = -Wall -g -std=c99

all: myavl

main: main.o myavl.o myavl.h
	gcc $(CFLAGS) main.o myavl.o -o main -ltinfo

main.o : main.c myavl.c 
	gcc $(CFLAGS) -c main.c -ltinfo

myavl: myavl.o 
	gcc $(CFLAGS) myavl.o -o myavl -ltinfo

myavl.o : myavl.c 
	gcc $(CFLAGS) -c myavl.c -ltinfo

clean:
	rm -rf ./*.o
	 
purge: clean
	rm -rf main