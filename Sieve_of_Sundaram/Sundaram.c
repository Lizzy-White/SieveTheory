#include "../sieve.h"

void init_sieve(sieve_t* sieve, int limit) {
	sieve->nums = malloc(sizeof(primality_t)*(limit + 1));
	sieve->primes = malloc(sizeof(int));
	memset(sieve->nums, NEITHER, sizeof(primality_t)*(limit + 1));
	sieve->num_primes = 0;
}

void sundaram_find_primes(sieve_t *sieve, int limit) {
	int i, j, k;
	i = 1;
	
	for (j = 1; j <= i; j++) {
		for (i = 1; i <= limit; i++) {
			if ((i+j+2*i*j) <= limit) {
				sieve->nums[i+j+2*i*j] = COMPOSITE;
				print_as_grid(sieve, limit);
			}
		}
	}

	sieve->primes[sieve->num_primes++] = 2;

	for (k = 1; k <= limit; k++) {
		if ((sieve->nums[k]) != COMPOSITE) {
			sieve->primes = realloc(sieve->primes, sizeof(int)*(++sieve->num_primes));
			sieve->primes[sieve->num_primes - 1] = 2*k+1;
			print_as_grid(sieve, limit);
//			print_as_list(sieve, limit);
		}
	}

	printf(N "\n");

}

void print_as_list(sieve_t sieve, int limit) {
	int i;
	printf(N "\nThere are %d primes <= %d: \n", sieve.num_primes, 2*limit);

	for (i = 0; i < sieve.num_primes; i++) {
			printf("%d\n", sieve.primes[i]);
	}

	printf("\n");
}

void print_as_grid(sieve_t* sieve, int limit) {
	int i, num_cols, col_count;
	num_cols = sqrt(limit);
	col_count = 0;
	printf(N "\n\n");
	for (i = 1; i <= limit; i++) {
		if (col_count == num_cols) {
			printf(N "\n");
			col_count = 0;
		}
		if (isprime(*sieve, i))	
			printf(P "%4d", i);
		else if (sieve->nums[i] == COMPOSITE)
			printf(C "%4d", i);
		else
			printf(N "%4d", i);
		col_count++;
	}
	usleep(50000);

}

bool isprime(sieve_t sieve, int i) {
	int j;
	for (j = 0; sieve.primes[j] <= i && j < sieve.num_primes; j++)
		if (sieve.primes[j] == i)
			return true;
	return false;
}

void uninit_sieve(sieve_t* sieve) {
	free(sieve->nums);
}
