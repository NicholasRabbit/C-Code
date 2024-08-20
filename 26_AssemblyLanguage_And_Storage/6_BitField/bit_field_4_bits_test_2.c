

/*
 * What is the result of 7 minus -8 in a 4 bits data type?
 * */
# include<stdio.h>


typedef struct {
	unsigned int v:4;
} four_bits;

int main (void) 
{
	
	four_bits m, n, r;
	m.v = 7;
	n.v = -8;
	
	r.v = m.v - n.v;

	printf("7-(-8) is ==> %u\n", r.v);
	/*
	 * The result is 15 which is beyond the range of 4-bits data type and is eventually
	 * truncated off the most significant 1 so that the real result is -1 for 4 bits.
	 * */

	return 0;
}


