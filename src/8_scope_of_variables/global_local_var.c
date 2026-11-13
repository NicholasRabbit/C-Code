#include <stdio.h>

int i = 0xabc;


int add(int i, int j); 

int main(int argc, char *argv[])
{

	int j = 0xff;

	add(i, j);

	return 0;
}

int add(int i, int j)
{
	return i + j;
}
