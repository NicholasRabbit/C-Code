#include <stdio.h>

int main(int argc, char *argv[])
{

	char c = 3;
	switch (c) {
		default: 
			printf("default\n");
		case 2: 
			printf("case 2\n");
			break;
		case 3:
			printf("case 3\n");
			break;
	}

	return 0;
}
