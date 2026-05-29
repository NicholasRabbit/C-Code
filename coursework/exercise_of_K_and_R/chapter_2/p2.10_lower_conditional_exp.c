#include <stdio.h>

int lower2(char c) 
{
	/* // A conditional control transfer.
	if (c >= 'A' && c <= 'Z') 
		return c + 'a' - 'A';
	else
		return c;
	*/

	// A conditional data transfer. 
	return (c >= 'A' && c <= 'Z') ? (c + 'a' - 'A') : c;
}


int main(int argc, char *argv[])
{
	int c;
	while ((c = getchar()) != '\n') {
		char lower_c = lower2(c);
		printf("%c ", lower_c);
	}
	printf("\n");
	return 0;
}
