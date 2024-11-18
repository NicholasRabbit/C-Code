#include <stdio.h>
#include <string.h>


int main (void) 
{

	/*
	 * 6, If a char array were delcared in a curly brace-{}, the function "strlen(...)" will continue reading
	 * memory until '\0' is found so that the result may not be as expected.
	 * */
	char s[] = {'a', 'b'};
	printf("strlen(s) = \%lu\n", strlen(s));  // The result is 6 or something else.

	// We should add a null terminator '\0' manually.
	char t[] = {'a', 'b', '\0'};
	printf("strlen(t) = \%lu\n", strlen(t));  // The result is 6 or something else.
	


	return 0;
}
