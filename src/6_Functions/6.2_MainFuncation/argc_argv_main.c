#include <stdio.h>

/*
 * "argc" is short for "argumetns count" which indicates the nubmer 
 * of the input arguments.
 * "argv[]" stores the arguments as char array.
 *
 * Run:
 * ./argc_argv_main.out a b c
 * The output is
 * 0 ./argc_argv_main  : the name of this function
 * 1 a
 * 2 b
 * 3 c
 *
 * */

int main(int argc, char *argv[])
{
	printf("The number of arguments is: %d\n", argc);

	int i;
	for (i = 0; i < argc; i++) {
		printf("Argument: %d %s\n", i, argv[i]);
	}
	return 0;
}
