#include <stdio.h>

int isspace2(char c);


int main(int argc, char *argv[])
{
	int c;
	while (isspace2(c = getchar()))
	   ;	
	return 0;
}

int isspace2(char c)
{
	return c == ' ';
}
