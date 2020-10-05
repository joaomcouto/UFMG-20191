
CC = gcc 
CFLAGS = -Wall -std=c99  

all: build clean

build: main.o grafo.o testes.o 
	$(CC) $(CFLAGS) main.o grafo.o testes.o -o tp3 -lm

main.o:
	$(CC) $(CFLAGS) -c main.c -o main.o

grafo.o:
	$(CC) $(CFLAGS) -c grafo.c -o grafo.o

testes.o:
	$(CC) $(CFLAGS) -c testes.c -o testes.o



clean:
	rm *.o
