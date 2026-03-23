#include <stdio.h>

// Delete 'c' in an array.
// Trying rewriting the example code after reading this chapter. 
void squezze(char s[]);  // I forgot the second argument "int c".


int main(int argc, char *argv[])
{
	char s[8] = {'a', 'x', 'c', 'd', 'e', 'c', 'H', '\0'};

	squezze(s);
	printf("%s\n", s);

	return 0;
}

void squezze(char s[])
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; i++) 
		if (s[i] != 'c')
			s[j++] = s[i];

	s[j] = '\0';
}
