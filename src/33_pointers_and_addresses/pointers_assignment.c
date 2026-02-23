#include <stdio.h>

int main(int argc, char *argv[])
{
	char c, *cp;
	c = 'a';
	cp = &c;
	printf("%c\n", *cp);

	/*
	 * Note that assigning a pointer when it is declared is different from 
	 * giving a value to the object the pointer deferences.
	 * If we assign "*ptc" with "cp" as in Label A, it is wrong.
	 * */
	char *ptc = cp; // It is as same as "char *ptc; ptc = cp", but NOT like *ptc = 'a'.
	ptc = cp;

	// *ptc = cp; // A: NOT appropriate!
	
	printf("%c\n", *ptc);
	

	return 0;
}
