#include <stdio.h>

/*
 * What are the differencs between "x += 1" and "x = x + 1" except for 
 * the conciseness of code?
 * */
int main(int argc, char *argv[])
{
	int i = 2, j = 3;

	i = i + 5;
	j += 6;
	

	return 0;
}
