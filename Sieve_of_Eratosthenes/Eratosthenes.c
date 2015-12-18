#include "../sieve.h"

void init_sieve(sieve_t* sieve, int limit) {
	sieve->nums = malloc(sizeof(primality_t)*(limit + 1));
	memset(sieve->nums, NEITHER, sizeof(primality_t)*(limit + 1));
	sieve->num_primes = 0;
}

void eratosthenes_find_primes(sieve_t *sieve, int limit) {
	int i, multiple;
	int upper_bound = find_upper_bound(limit);

	for (i = 2; i <= upper_bound; i++) {
		if (sieve->nums[i] == COMPOSITE)
			continue;
		sieve->nums[i] = PRIME;
		sieve->num_primes++;
		multiple = i*2;
		while (multiple <= limit) {
			if (sieve->nums[multiple] != COMPOSITE) 
				sieve->nums[multiple] = COMPOSITE;
			print_as_grid(sieve, limit);
			multiple += i;
		}
	}

	for (i = upper_bound + 1; i <= limit; i++) {
		if (sieve->nums[i] == NEITHER) {
			sieve->nums[i] = PRIME;
			sieve->num_primes++;
			print_as_grid(sieve, limit);
		}
	}
	printf(N "\n");
}

int find_upper_bound(int limit) {
	return ceil(sqrt(limit));
}

void print_as_list(sieve_t sieve, int limit) {
	int i;
	printf(N "\nThere are %d primes <= %d: \n", sieve.num_primes, limit);

	for (i = 2; i <= limit; i++) {
		if (sieve.nums[i] == PRIME) 
			printf("%d\n", i);
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
		if (sieve->nums[i] == PRIME)	
			printf(P "%4d", i);
		else if (sieve->nums[i] == COMPOSITE)
			printf(C "%4d", i);
		else
			printf(N "%4d", i);
		col_count++;
	}
	usleep(10000);

}

void uninit_sieve(sieve_t* sieve) {
	free(sieve->nums);
}
