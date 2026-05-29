#include <stdio.h>

// The is a function named `getline()` in the C library, 
// therefore, I use `get_line`. 
int get_line(char s[], int lim)
{
	int i, c;
	i = 0;
	while (i < lim - 1 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n') 
		s[i++] = c;		// '\n' takes a room in terms of the length of the line.
	s[i] = '\0';

	return i;
}
