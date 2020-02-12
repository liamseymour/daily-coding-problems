/* (EASY)
 * This problem was asked by Alibaba.
 * Given an even number (greater than 2), 
 * return two prime numbers whose sum will be 
 * equal to the given number. */


#include <stdio.h>
#include <stdlib.h>

int isprime(int n);
void goldbach(int n, int *p1, int *p2);

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Enter an even integer > 2.\n");
		return 1;
	}

	int n = atoi(argv[1]);
	if (n <= 2 || n % 2 == 1) {
		printf("Enter an even integer > 2.\n");
		return 2;
	}

	int p1 = 0;
	int p2 = 0;
	goldbach(n, &p1, &p2);
	printf("%d = %d + %d\n", n, p1, p2);
	return 0;
}

void goldbach(int n, int *p1, int *p2)
{
	/* Create a list of available primes */
	int *primes = malloc(sizeof(n) * n);
	int current = 0;
	for (int i = 2; i < n; ++i) {
		if (isprime(i))
			primes[current++] = i;
	}
	
	/* Check for primes that sum to n and store them in p1 and p2 */
	for (int i = 0; i < current; ++i) {
		for (int j = 0; j <= i && j < current; ++j) {
			if (primes[i] + primes[j] == n) {
				*p1 = primes[i];
				*p2 = primes[j];
				free(primes);
				return;
			}
		}
	}

	free(primes);
	*p1 = *p2 = -1;
	return;
}

int isprime(int n)
{
    /* Simple primality test adopted from https://en.wikipedia.org/wiki/Primality_test#Simple_methods */

    if (n <= 3) {
        return 1;
    }

    if (n % 2 == 0 || n % 3 == 0) {
        return 0;
    }

    int i; 
    for (i = 5; i * i <= n; i += 6) {
        if (((n % i) == 0 )|| ((n % (i + 2)) == 0)) {
            return 0;
        }
    }

    return 1;
}
