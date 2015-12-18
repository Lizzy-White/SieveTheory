cc = gcc
CFLAGS = -g -Wall -lm

all: eratosthenes

eratosthenes: Eratosthenes.o main.o
	$(CC) $(CFLAGS) -o eratosthenes Eratosthenes.o main.o

Sundaram.o: Eratosthenes.c ../sieve.h
	$(CC) $(CFLAGS) -c Eratosthenes.c

main.o: main.c ../sieve.h
	$(CC) $(CFLAGS) -c main.c

clean: 
	$(RM) *.o eratosthenes
