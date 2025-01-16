#include <stdio.h>

/*
 * To print the histogram of frequencies of characters.
 * Before we write code, we should know the fact that capital letters 
 * are represented by consecutive numeric values in ASCII. So are the 
 * non-capital letters.
 * */
int frequency() 
{
	int c, i, count, n_char[26];
	i = count = 0;

	// Intialise the array.
	for (i = 0; i < 26; i++)
		n_char[i] = 0;
	
	// Input characters only.
	while ((c = getchar()) != EOF) {
		if (c >= 'a' && c <= 'z' )
			++n_char[c - 'a'];
	
	}


	for (i = 0; i < 26; i++) 
		printf("%c ", 'a' + i);
	printf("\n");


	for (i = 0; i < 26; i++) 
		printf("%d ", n_char[i]);
	printf("\n");

	return 0;

}




int main(void) 
{
	frequency();

	return 0;

}
