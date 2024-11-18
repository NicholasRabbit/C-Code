# include<stdio.h>

/*
 * The following code are shown the usage of bitwise operators in C.
 * */
int main (void) 
{
	
	// 1, |
	int m = 0x4321 | 0xFF;
	printf("0x%x\n", m);

	// 2, &
	m = 0x4321 & 0xFF;
	printf("0x%x\n", m);

	// 3, ^
	m = 0x4321 ^ 0xFF;
	printf("^: 0x%x\n", m);

	// 4, >> and <<
	m = 0xFF >> 2;
	printf(">>: 0x%x\n", m);
	m = 0xFF << 2;
	printf("<<: 0x%x\n", m);

	// 5, ~(flip all of the bits)
	m = ~0x42;
	printf("~: 0x%x\n", m);

	return 0;

}
