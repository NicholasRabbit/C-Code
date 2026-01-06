#include <stdio.h>


void get_char(char *cp);

int main(int argc, char *argv[])
{

	char *cp;
	cp = "Hi !";
	get_char(cp);
	printf("In main: cp = %p, *cp = %c\n", cp, *cp);

	return 0;
}


void get_char(char *cp)
{

	/*
	 * Note that the following assignment of "cp" modify the 
	 * value of the local variable "cp" so it doesn't alter the
	 * value in the calling fuction, therefore, "*cp" is still "a"
	 * in the calling function. 
	 * Here is the local variable "cp" which is distinct from that one in the calling function.
	 * */
	cp = "Jerry";  
	printf("In get_char: cp = %x\n", cp);

}
