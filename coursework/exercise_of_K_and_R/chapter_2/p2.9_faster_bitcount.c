#include <stdio.h>

/*
 * To compare the assembly code between bitcount in the book and the optimised verion,
 * I rewrite the function of bitcount here.
 * */
int bitcount(unsigned x)
{
	int n;
	for (n = 0; x != 0; x >>= 1)
		if (x & 01)  // 01 is an octo number. 
			n++;
	return n;
}


int bitcount_optmise(unsigned x)
{
	if (x == 0)
		return 0;

	int count = 0;
	do {
		count++;
	} while (x &= (x - 1));

	return count;
}

int bitcount_optmise2(unsigned x)
{
	int count;
	// Note that x is unsigned, therefore, the condition should NOT be x >= 0, or it will 
	// have an endless loop.
	for (count = 0; x != 0; x &= (x - 1))
		count++;
	return count;
}


int main(int argc, char *argv[])
{

	int x = 0b11001001;
	int count = 0;
	count = bitcount(x);
	printf("1: %d\n", count);
	//int count = bitcount_optmise(x);
	count = bitcount_optmise2(x);
	printf("2: %d\n", count);
	return 0;
}
