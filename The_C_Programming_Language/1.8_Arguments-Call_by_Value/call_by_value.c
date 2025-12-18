# include<stdio.h>

/*
 * This is not the example of this chapter but it is 
 * written to verify that functions are called by value.
 *
 * */

int add(int i, int j);
void get_char(char *cp);

int main(int argc, char *argv[])
{

	int a, b;
	a = 1;
	b = 3;
	int i = add(a, b);
	printf("a = %d, b = %d, i = %d\n", i, a, b);

	char *cp;
	cp = "a";
	get_char(cp);
	printf("cp = %p, *cp = %c\n", cp, *cp);

	return 0;
}

int add(a, b)
{
	a = 2;
	b = 6;
	return a + b;
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
	cp = "A";  
	printf("In get_char, cp = %x\n", cp);

}
