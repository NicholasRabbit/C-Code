# include<stdio.h>


/*
 * shifting bits by the amount of -1 or 31
 * */
int main (void) 
{
	int i = 0x5;

	i = i >> -1;

	printf("i = 0x%.4x\n", i);

	int j = i << 31;
	printf("j = 0x%.4x\n", j);

	// What will happen when shifting 8 bits for a byte?
	// There is no byte type in C but we can use char instead.
	unsigned char byte = 0xff;
	unsigned int left_shift_result = byte << 8;
	unsigned int right_shift_result = byte >> 8;

	printf("left_shift_result = 0x%X\n", left_shift_result);
	printf("right_shift_result = 0x%X\n", right_shift_result);

	return 0;
}
