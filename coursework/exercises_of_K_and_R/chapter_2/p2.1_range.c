#include <stdio.h>


void int_range(int s);
void long_range();
void char_range();
void single_precision_float();

int main(int argc, char *argv[])
{
	char_range();

	int_range(1);
	int_range(0);

	long_range();

	single_precision_float();

	return 0;
}

//char
void char_range()
{
	unsigned char c;
	c = ~0;
	c >>= 1;
	printf("The maximum signed char:	%4d\n", c);
	printf("The minimum signed char:	%x\n", -c);
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
	printf("The minimum signed long integer is %ld, hexadecimal: 0x%lx\n", min_long, min_long);

	long max_long = min_long - 1;  // It is the same with 127 + 1 = 128(-128 in two's complement).
	printf("The maximum signed long integer is %ld, hexadecimal: 0x%lx\n", max_long);

}


void single_precision_float() 
{


	// The book hasn't introduced "union" by this chapter; there must be other alternative approaches.
	// If I find any other solution, I will add it. 
	union {
		unsigned u;
		float f;
	} num;
	
	// The bits representation of the maximum single-precision floating value.
	unsigned max = 0x7f7fffff;
	num.u = max;
	float f = num.f;

	printf("The maximum single-precision float is %f\n", f);

}

