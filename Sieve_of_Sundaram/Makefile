cc = gcc
CFLAGS = -g -Wall -lm

all: sundaram

sundaram: Sundaram.o main.o
	$(CC) $(CFLAGS) -o sundaram Sundaram.o main.o

Sundaram.o: Sundaram.c ../sieve.h
	$(CC) $(CFLAGS) -c Sundaram.c

main.o: main.c ../sieve.h
	$(CC) $(CFLAGS) -c main.c

clean: 
	$(RM) *.o sundaram
