#include <stdio.h>

/*
 * Return the rightmost index if a pattern is matched in a line.
 * */
int strindex_rightmost(char source[], char searchfor[])
{
	int i, j, k;
	for (i = 0; source[i] != '\0'; i++) {
		for (j = i, k = 0; searchfor[k] != '\0' && source[j] == searchfor[k]; j++, k++) 
			;
		if (k > 0 && searchfor[k] == '\0') 
			return j - 1;	// return the rightmost index of the pattern.
	}
	

	return -1;
}

