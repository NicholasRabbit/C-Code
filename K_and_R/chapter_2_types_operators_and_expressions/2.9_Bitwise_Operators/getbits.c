#include <stdio.h>

/*
 * Note that the rightmost bit starts at an index of 0. 
 * */
unsigned getbits(unsigned x, int p, int n)
{
	return (x >> (p + 1 - 3)) & ~(~0 << n);
}


int main(int argc, char *argv[])
{
	unsigned int ui = 0b01101100;
	unsigned int ubits = getbits(ui, 4, 3);
	printf("0x%x\n", ubits);
	return 0;
}
