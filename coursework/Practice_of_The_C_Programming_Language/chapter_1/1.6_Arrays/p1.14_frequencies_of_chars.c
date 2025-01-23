#include <stdio.h>

#define N 26

/*
 * To print the histogram of frequencies of characters.
 * Before we write code, we should know the fact that capital letters 
 * are represented by consecutive numeric values in ASCII. So are the 
 * lower cases.
 * */
int frequency() 
{
	int c, i, count, n_char[N], cap_char[N];
	i = count = 0;

	// Intialise the array.
	for (i = 0; i < N; i++) {
		n_char[i] = 0;
		cap_char[i] = 0;
	}
	
	// Input characters only.
	while ((c = getchar()) != EOF) {
		// Lower cases
		if (c >= 'a' && c <= 'z' )
			++n_char[c - 'a'];

		// Capital letters
		if (c >= 'A' && c <= 'Z')
			++cap_char[c - 'A'];
	
	}


	// occurrences of lower cases
	for (i = 0; i < N; i++) 
		printf("%c ", 'a' + i);
	printf("\n");

	for (i = 0; i < N; i++) 
		printf("%d ", n_char[i]);
	printf("\n");


	// occurrences of capital letters.
	for (i = 0; i < N; i++) 
		printf("%c ", 'A' + i);
	printf("\n");

	for (i = 0; i < N; i++) 
		printf("%d ", cap_char[i]);
	printf("\n");
	return 0;

}




int main(void) 
{
	frequency();

	return 0;

}
