#include "Eratosthenes.h"

primality_t* init_sieve(primality_t* nums, int limit) {
	nums = malloc(sizeof(primality_t)*(limit + 1));
	memset(nums, PRIME, sizeof(primality_t)*(limit + 1));
	nums[0] = nums[1] = NEITHER;
}

void find_primes(primality_t *nums, int limit) {
	double upper_bound = sqrt(limit);
	upper_bound = ceil(upper_bound);

	int i, multiple;
	for (i = 2; i <= upper_bound; i++) {
		multiple = i*2;
		while (multiple <= limit) {
			nums[multiple] = COMPOSITE;
			multiple += i;
		}
	}	
}

void print_as_list(primality_t* nums, int limit) {
	int i;
	printf("\nLIST OF PRIMES"
			"\n2");
	
	for (i = 3; i <= limit; i++) {
		if (nums[i] == COMPOSITE)
			printf(", %d", i);
	}
printf("Value of 3 is %d", nums[3]);
	printf("\n");
}
