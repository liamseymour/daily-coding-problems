/* (MEDIUM)
 * This problem was asked by Indeed.
 * Given a 32-bit positive integer N, 
 * determine whether it is a power of 
 * four in faster than O(log N) time. */

#include <stdio.h>
#include <stdlib.h>
int isPowerFour(int n);

int main(int argc, char **argv)
{
	if (argc == 1)
		return 1;

	int n = atoi(argv[1]);
	
	if (isPowerFour(n)) {
		printf("%d is a power of four.\n", n);
	} else {
		printf("%d is not a power of four.\n", n);
	}

	return 0;
}

int isPowerFour(int n) {
	/* Basic strategy here is that powers 
	 * of four have one and only one bit 
	 * that is set in one of these positions:
	 *
	 * ... _ ? _ ? _ ? _ ? _ ? _ ? 
	 *
	 * Because our input is only ever 32 bits, 
	 * checking all 32 of these bits is constant */

	int found = 0; // number of set bits
	int iter; // What iteration we are on
	int fourBit = 0; // have we found one of the bits described above?
	for (int mask = 1; mask > 0 && found < 2; mask <<= 1) {
		if (n & mask)
			found++;

		if ((iter % 2 == 0) && (n & mask))
			fourBit++;
		iter++;
	}
	return fourBit && (found < 2);
}
