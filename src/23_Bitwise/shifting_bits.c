# include<stdio.h>


int main (void) 
{
	/*
	 * 1. shifting bits by the amount of -1 or 31
	 * */
	int i = 0x5;
	i = i >> -1;

	printf("i = 0x%.4x\n", i);

	int j = i << 31;
	printf("j = 0x%.4x\n", j);

	// 2. What will happen when shifting 8 bits for a byte?
	// There is no byte type in C but we can use char instead.
	unsigned char byte = 0xff;
	unsigned int left_shift_result = byte << 8;
	unsigned int right_shift_result = byte >> 8;

	printf("left_shift_result = 0x%X\n", left_shift_result);
	printf("right_shift_result = 0x%X\n", right_shift_result);

	
	// 3. >>= : It is as same as " m = m >> 2". 
	// We treat bit operators like ">>" as same as "+, -, *, /, %" and so forth.
	int m = 0xff;
	m >>= 2;
	printf("m >>= 2 is: %x\n", m);
	
	int n = 0xff;
	n >> 2;
	printf("n >>= 2 is: %x\n", n); // n is still "0xff".


	return 0;
}
