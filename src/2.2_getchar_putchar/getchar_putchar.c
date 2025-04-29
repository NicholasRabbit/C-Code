#include <stdio.h>

/*
 * getchar() and putchar(...) 
 *
 * N.B. The 'getchar()' only gets a single character each time.
 * So the 'putchar(...)' print a character each time it is called.
 * */

int get()
{
	int c;
	while ((c = getchar()) != EOF)
		printf("%c\n", c);

	return 0;
	
}

int get_put() 
{
	int c;
	c = getchar();

	while (c != EOF) {
		putchar(c);
		c = getchar();
	}

	return 0;
}


int main(void) 

{

	get();
//	get_put();

	return 0;

}
