#include <stdio.h>

#define N 32

unsigned show_bits(unsigned u)
{
	char ua[N];
	int i;
	for (i = 0; i < N; i++)
		ua[i] = 0;

	i = 0;
	while (u > 0) {
		ua[i] = u & 0x1;
		u >>= 1;
		i++;
	}
	
	i -= 1;
	while (i >= 0) {
		printf("%d", ua[i]);
		i--;
	}
	printf("\n");

	return u;

}


unsigned setbits(unsigned x, int p, int n, unsigned y)
{
	// 1. First of all, extract the rightmost n bits of y.
	unsigned int mask = ~(~0 << n);
	y = y & mask;
	// 2. Move the extracted bits to left with the starting position of "p";
	y <<= p + 1 - n;
	// 3. Creata a mask of bits to set the "n" bits from "p" to the right to 0.
	mask <<= p + 1 - n;
	mask = ~mask;
	//show_bits(mask);
	
	// 4. Set all the n bits in "x" starting from "p" to the right to 0.
	show_bits(x);  // before
	x = x & mask;
	//show_bits(x);	// After 

	// 5. Let x do OR with y.
	x = x | y;
	show_bits(x);


	
	return y;
}

int main(int argc, char *argv[])
{
	int x, p, n, y;
	x = 0b01101001;
	p = 4;
	n = 3;
	y = 0b11000101;
	setbits(x, p, n, y);
	return 0;
}


