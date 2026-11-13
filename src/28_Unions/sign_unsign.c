#include <stdio.h>


int main(int argc, char *argv[])
{

	union {
		int i;
		unsigned ui;
	} temp;

	temp.i = -1;

	printf("%u\n", temp.i);
	

	return 0;
}
