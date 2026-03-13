#include <stdio.h>


void arg1(arg)
{
	char c = arg;
}

void arg2(char c)
{
	char c2 = c;
	printf("c2 is %c\n", c2);
}


/*
 * In the main function, since the caller, namely "main", doesn't "see"
 * the prototype of argument, the parameter will be converted to int automatically.
 * That happens both of the calling of "arg1" and "arg2", even though the type of 
 * the argumentis delcared in the function "arg2".
 * See the assembly code, "c" has been extended by "movzbl or movsbl".
 * */
int main(int argc, char *argv[])
{
	char c;
	arg1(c);
	arg2(c);

	return 0;
}
