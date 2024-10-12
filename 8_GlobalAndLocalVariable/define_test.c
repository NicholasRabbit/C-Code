#include <stdio.h>

/*
 * Symbolic constants in C.
 *
 * "#define" is used to declare "symbolic names" or "symbolic constants".
 * The format is:
 * #define NAME replacement
 *
 * Notice that the symbolica constant names is conventionally written in 
 * upper case.
 *
 * The "replacement" is not limited to integer number but also could be 
 * characters and other data types.
 * */
#define ID 1001
#define NAME "Tom"

int main(void) 
{
	printf("%d\n", ID);

	printf("%c\n", NAME[0]);
	
	printf("%s\n", NAME);

	return 0;
}
