# include<stdio.h>

/*
 * This is not the example of this chapter but it is 
 * written to verify that functions are called by value.
 *
 * */

int add(int i, int j);

int main(int argc, char *argv[])
{

	int a, b;
	a = 1;
	b = 3;
	int i = add(a, b);
	printf("a = %d, b = %d, i = %d\n", i, a, b);


	return 0;
}

int add(a, b)
{
	a = 2;
	b = 6;
	return a + b;
}


