# include<stdio.h>


/*
 * The aim of this programmer it to define a data type with 4 bits to 
 * test unsigned addition. Because the range of 4 bits is quite small
 * so that it is easy to test and to verify whether the result is correct
 * or not.
 *
 * Seee page 81 on CSAPP(2rd).
 * */
typedef struct {
	unsigned int v:4;
} four_bits;


int main(void) 
{

	/*
	 * The range of the value of 4 bits is from 0 to 15.
	 * What is the result if we add 15 to 6?
	 * The result is 5. But why?
	 * Because when a result of unsigned addition is larger its maximum number,
	 * it is equivalent to modular arithmetic.
	 * Namely, 15 + 6 = 21, 21 % 16 = 5.
	 * */
	four_bits k, j, result;
	k.v = 15;
	j.v = 6;
	result.v = k.v + j.v;

	printf("k.v = %u\n", k.v);
	printf("result.v = %u\n", result.v);

	return 0;

}
