#include <stdio.h>


// Conditional control transfer.
int max1(int a, int b)
{
	int z;
	if (a > b)
		z = a;
	else 
		z = b;
	return z;
}


// Conditional data transfer.
int max2(int a, int b)
{
	return a > b ? a : b;
}



int main(int argc, char *argv[])
{
	
	max1(1, 2);
	max2(1, 2);

	return 0;
}
