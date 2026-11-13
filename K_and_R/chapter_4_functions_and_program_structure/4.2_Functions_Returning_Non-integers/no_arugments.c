#include <stdio.h>

int atoi();
int void_arg(void);


int main(int argc, char *argv[])
{
	// For "atoi()" with no empty list of arguments, the type of arguments is also not assuned as in an undeclaration. 
	char s[8] = "abc";
	atoi(s);
	double d = 1.5;
	atoi(d);
	
	// Whereas, for a function with an argument of "void", it is literally an "empty" list of arguments.
	//void_arg(s);	// An error occurs when it is compiled: too many arguments.
	void_arg();	// Calling a function with "void" as its argument.

	return 0;
}

int void_arg(void)
{
	return 0;
}
