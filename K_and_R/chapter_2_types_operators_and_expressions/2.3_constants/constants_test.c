#include <stdio.h>

// Octo number '\0123'
// '\013' is a character represented by an octo number.
// The first \0 is an escape symbol, not the terminal '\0'.
#define VTAB '\013'		// It is as same as '\v'.
#define BELL '\007'		// It is '\a'.

// Hexadecimal numbers
#define VTAB_H '\xb'
#define BELL_H '\x7'

int main(int argc, char *argv[])
{
	
	printf("VTAB(octo): 0%o\n", VTAB);
	printf("%c\n", VTAB);	// It prints a vertical tab.

	printf("%c\n", BELL);	// The ternimal can play a sound when BELL is printed to the console. 


	printf("%c\n", VTAB_H);	// It prints a vertical tab.
	printf("%c\n", BELL_H);	// The ternimal can play a sound when BELL is printed to the console. 

	return 0;
}
