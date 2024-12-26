#include <stdio.h>


/*
 * Some functions and preserved words such as 'switch', 'continue' have not been
 * introduced before the quesion in the book, so it is not allowed to use them in
 * the solution.
 * */
int display_symbols()
{
	int c;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			putchar('\\');
			putchar('t');

		// '\b' is Backspace not Space. N.B. 
		// Directly pressing 'Backspace' in CLI could not input '\b' to the application. 
		// Instead, to press 'Ctrl + H' or "Shift + BackSpace" works.
		} else if (c == '\b') {  
			putchar('\\');
			putchar('b');
		
		} else if (c == '\\') {
			putchar('\\');
			putchar('\\');
		} else {
			putchar(c);
		}
	
	}


	return 0;
}


int main(void) 
{

	display_symbols();

	return 0;
}

