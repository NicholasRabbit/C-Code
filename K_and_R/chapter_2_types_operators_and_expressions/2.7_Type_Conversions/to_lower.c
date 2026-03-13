#include <stdio.h>


int to_lower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 'a' - 'A';
	else
		return c;
}


int main(int argc, char *argv[])
{

	int c;
	while ((c = getchar()) != '\n') {
		printf("%c\n", to_lower(c));
	}


	return 0;
	
}
