#include <stdio.h>


int replace_blanks()
{
	int c, count;
	count = 0;

	while ((c = getchar()) != EOF) {
		if (count < 1 && c == ' ') {
			putchar(c);
			count++;
		}

		if (c != ' ') {
			putchar(c);
			count = 0;
		}

	
	}


	return 0;
}



int main(void) 
{
	replace_blanks();
	return 0;
}
