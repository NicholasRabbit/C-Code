#include <stdio.h>


int main(void) 
{
	int c;
	c = getchar() != EOF;

	printf("c is %d\n", c);

	return 0;
}
