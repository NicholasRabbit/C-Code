#include <stdio.h>

int main(void) 
{
	
	int c;
	/*
	 * Note that in C the precedence of "!=" is higher than "=".
	 * The parentheses in the condition "(c = getchar()) != EOF" should not be 
	 * omitted because "c = getchar() != EOF" is equivalent to "c = (getchar() != EOF)"
	 * , which means that "getchar() != EOF" is executed first and then the "c" will be 
	 * set to "0" or "1".
	 * */
	while ((c = getchar()) != EOF) {
		putchar(c);
	}
	

	return 0;
}
