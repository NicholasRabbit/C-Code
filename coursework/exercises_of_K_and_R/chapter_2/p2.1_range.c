#include <stdio.h>


void int_range(int s);
void long_range();

int main(int argc, char *argv[])
{

	int_range(1);
	int_range(0);

	long_range();
	return 0;
}

// s: 1 signed, 0 : unsigned.
void int_range(int s) 
{
	if (s) {
		int min = 1 << 31;
		printf("mininum integer is %d\n", min);

		unsigned int max = 0xffffffff >> 1;  // Logical shifting fills the left ends with 0s. 
		printf("maximum integer is %d\n", max);
	
	} else {
		unsigned u_min = 0;
		printf("unsigned minimum integer %u\n", u_min);
		unsigned u_max = ~0; 
		printf("unsigned maximum integer %u\n", u_max);


	}
}

void long_range() 
{
	/*
	 * Note that the following is treated as an integer by default, therefore, it can't 
	 * be shifted by 63 bits. There will an an warning: count >= 32, which indicates "1"
	 * is an integer. 
	 * */
	//long ming_long = 1 << 63;  
	long min_long = 1;
	min_long <<= 63;
	//min_long = 0x8fffffffffffffff;
	printf("minimum signed long integer is %ld\n", min_long);

	unsigned long max_long = min_long + 1;  // It is the same with 127 + 1 = 128(-128 in two's complement).
	printf("maximum signed long integer is %ld\n", max_long);

}
