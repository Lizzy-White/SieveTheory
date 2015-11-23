#ifndef H_ERATOSTHENES_H
#define H_ERATOSThENES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef enum primality {
	COMPOSITE,
	PRIME,
	NEITHER	
} primality_t;

primality_t* init_sieve(primality_t* nums, int limit);
void find_primes(primality_t* nums, int limit);
void print_as_list(primality_t* nums, int limit);
void uninit_sieve(primality_t*);

#endif
