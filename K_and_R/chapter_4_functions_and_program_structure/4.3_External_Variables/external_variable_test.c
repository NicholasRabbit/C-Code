#include <stdio.h>

int i, j;

int add()
{
	return i + j;
}


int main(int argc, char *argv[])
{
	
	i = 1;
	j = 2;
	add();
	return 0;
}
