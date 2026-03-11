#include <stdio.h>


int main(void) 
{
	char c;

	int count = 0;
	while ( (c = getchar()) != EOF) {
		if (count == 0 && c == ' ') {
			putchar('\n');
			count ++;
		}

		if (c != ' ') {
			putchar(c);
			count = 0;
		}

	}

	return 0;
}
