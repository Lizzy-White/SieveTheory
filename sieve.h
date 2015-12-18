#ifndef H_SIEVE_H
#define H_SIEVE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <unistd.h>

#define N "\x1b[0m"
#define P "\x1b[45m"
#define C "\x1b[44m"

/*
 * PRIMALITY
 * 		enumeration of possible primality types
 * 		used for array of integers up to the user-defined limit
 */
typedef enum primality {
	NEITHER,
	PRIME,
	COMPOSITE
} primality_t;

/*
 * SIEVE
 * 		holds the number of primes and
 * 		the array of numbers, utilizing the enum
 */
typedef struct sieve {
	primality_t* nums;
	int* primes;
	int num_primes;
} sieve_t;

/*
 * Malloc space for the sieve
 * Set all elements in the nums array to 'NEITHER' until decided
 * as PRIME or COMPOSITE
 * Sets the number of primes to 0
 */
void init_sieve(sieve_t* sieve, int limit);

/*
 *
 */
void eratosthenes_find_primes(sieve_t* sieve, int limit);
void sundaram_find_primes(sieve_t* sieve, int limit);
bool isprime(sieve_t sieve, int i);


/*
 * Calculates the square root of the user defined limit, rounding
 * up to the nearest whole integer
 */
int find_upper_bound(int limit);

/*
 * Prints the list of integers marked as prime
 */
void print_as_list(sieve_t sieve, int limit);

/*
 * Prints the array of all integers
 * Numbers found to be PRIME are pink
 * Numbers found to be COMPOSITE are blue
 * All other numbers will be the original white text
 */
void print_as_grid(sieve_t* sieve, int limit);

/*
 * Free the sieve
 */
void uninit_sieve(sieve_t* sieve);

#endif
