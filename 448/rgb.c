/* (HARD)
 * This problem was asked by Google.
 *
 * Given an array of strictly the characters 'R', 'G', and 'B', 
 * segregate the values of the array so that all the Rs come first, 
 * the Gs come second, and the Bs come last. 
 * You can only swap elements of the array.
 *
 * Do this in linear time and in-place.
 * For example, given the array ['G', 'B', 'R', 'R', 'B', 'R', 'G'], 
 * it should become ['R', 'R', 'R', 'G', 'G', 'B', 'B']. */

#include <stdio.h>
#include <stdlib.h>

void sort(char *rgb);
void swap(char *s, int i, int j);

int main(void)
{
	printf("Enter and rgb string to be sorted: ");
	char *rgb = NULL;
	size_t rgbSize;
	getline(&rgb, &rgbSize, stdin);
	
	sort(rgb);
	printf("Sorted: %s\n", rgb);

	free(rgb);
	return 0;
}

void sort(char *rgb)
{
	/* We can do this in two passes, maintaining linear time.
	 * For both passes maintain a pointer and increase
	 * it for each swap made.
	 * For the first pass swap ever R found with item at pointer
	 * Do the same for Gs
	 * all that is left are Bs so we can return 
	 * O(2n) = O(n)                                            */

	int pointer = 0;
	for (int i = 0; rgb[i] != '\0'; ++i) {
		if (rgb[i] == 'R' || rgb[i] == 'r') 
			swap(rgb, i, pointer++);
	}
	for (int i = 0; rgb[i] != '\0'; ++i) {
		if (rgb[i] == 'G' || rgb[i] == 'g') 
			swap(rgb, i, pointer++);
	}
	return;
}

void swap(char *s, int i, int j) 
{
	char temp = s[i];
	s[i] = s[j];
	s[j] = temp;
	return;
}
