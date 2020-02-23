/* [MEDIUM]
 * This problem was asked by LinkedIn.
 * 
 * You are given a string consisting of the letters x and y, 
 * such as xyxxxyxyy. In addition, you have an operation 
 * called flip, which changes a single x to y or vice versa.
 * 
 * Determine how many times you would need to apply this 
 * operation to ensure that all x's come before all y's. 
 * In the preceding example, it suffices to flip the second 
 * and sixth characters, so you should return 2. */

#include <stdio.h>
#include <string.h>

int minflips(char *xy);

int main(int argc, char **argv)
{
	if (argc < 2) {
		printf("Invalid usage, requires: string of x & y.\n");
		return 1;
	}

	char *xy = argv[1];
	int c = minflips(xy);
	printf("%d flips -> %s.\n", c, xy);

	return 0;	   	
}


int minflips(char *xy)
{
	/* One solution, in linear time is
	 * to consider each point where we
	 * can divide the list in two, all
	 * "y"s to the left must be flipped
	 * and all "x"s to the right must be
	 * flipped. This narrows the search
	 * space from 2^n to n+1. We do not
	 * need to check how many need flipped
	 * if we maintain how many "x"s and 
	 * "y"s are on each side. We return the
	 * minimum of the required flips. */

	int xyc = strlen(xy);
	int flips[xyc + 1]; // store required flips
	
	/* count total "x"s and "y"s,
	 * they will all be on the right */
	int rx, lx, ry, ly;
	rx = lx = ry = ly = 0;
	for (int i = 0; i < xyc; ++i) {
		if (xy[i] == 'x')
			rx++;
		else
			ry++;
	}
	
	/* record rquired flips
	 * for all on the right side. 
	 * i.e. flipping all "x"s to "y"s. */
	flips[0] = rx;

	for (int i = 0; i < xyc; ++i) {
		if (xy[i] == 'x') {
			lx++;
			rx--;
		} else {
			ly++;
			ry--;
		}
		flips[i+1] = ly + rx;
	}
	
	/* find minimum */
	int min = flips[0];
	int minI = 0;
	for (int i = 1; i < xyc+1; ++i) {
		if (flips[i] < min) {
			min = flips[i];
			minI = i;
		}
	}

	/* not required, but we will modify
	 * the string. */
	for (int i = 0; i < minI; ++i)
			xy[i] = 'x';
	for (int i = minI; i < xyc; ++i)
		xy[i] = 'y';
	
	return min;
}

