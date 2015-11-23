#include "Eratosthenes.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		printf("\nIncorrect number of command line arguments"
				"\nUsage: ./a.out <size_of_input>"
				"\nExiting...\n");
		return 0;
	}

	int limit = atoi(argv[1]);
	primality_t* nums = NULL;
	
	nums = init_sieve(nums, limit);
	find_primes(nums, limit);
	print_as_list(nums, limit);

	return 0;
}
