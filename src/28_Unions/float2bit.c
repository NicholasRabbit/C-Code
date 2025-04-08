#include <stdio.h>

/*
 * Unions provide a way to circumvent the type systems of C, allowing a single object
 * to be referenced as different types.
 * Since different data types are all represent by bits, it is tricky to get the bit representation
 * of a floating object by take advantage of the property of unions in C.
 * See Chapter 3.9.2 in "CSAPP".
 *
 * */
unsigned float_to_point(float f);


int main(void)
{
	unsigned u = float_to_point(0.5f);
	printf("%.2x\n", u);

	return 0;
}


unsigned float_to_point(float f)
{
	union {
		float f;
		unsigned u;

	} temp;

	temp.f = f;
	return temp.u;
}
