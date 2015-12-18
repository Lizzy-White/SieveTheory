#include <stdio.h>
#include "../sieve.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		fprintf(stderr, "\nInsufficient number of command line arguments.  Exiting...\n");
		return 0;
	}

	int limit = atoi(argv[1]);
	sieve_t sieve;

	init_sieve(&sieve, limit);
	sundaram_find_primes(&sieve, limit);
	print_as_list(sieve, limit);
//	uninit_sieve(&sieve);
	return 0;
}
