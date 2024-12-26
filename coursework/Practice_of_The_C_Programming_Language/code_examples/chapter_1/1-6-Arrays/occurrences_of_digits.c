#include <stdio.h>


/*
 * To count the number of occurrences of digits.
 *	
 * Using the index of an array to represent a particular number. 
 * For example, if ndigit[0] = 5, the number of occurrences of '0' is 5.
 * */
int main(void) 
{
	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;

	// initialise the array
	for (i = 0; i < 10; i++) {
		ndigit[i] = 0;
	}


	/*
	 * Why do we use [c-'0'] in the statement?
	 * In ASCII table numbers from '0' to '9' have consecutive numeric values in the 
	 * range between 48 to 57. For instance, 48 represents character '0' and 49 for '1'.
	 * Therefore, [c-'0'](like 49 - 48) is used to indicte the index of an array.
	 * */
	while( (c = getchar()) != EOF) {
		
		if (c >= '0' && c <= '9') {
			++ndigit[c - '0'];
		} else if (c == ' ' || c == '\n' || c == '\t') {
			++nwhite;
		} else {
			++nother;
		}
		
	}

	printf("digits = ");
	for(i = 0; i < 10; i++) 
		printf("%d ", ndigit[i]);

	printf(", white space = %d, other = %d\n", nwhite, nother);



	return 0;
}
