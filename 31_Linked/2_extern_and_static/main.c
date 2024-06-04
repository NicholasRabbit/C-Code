# include<stdio.h>

/*
 * What are the modifiers like "static" and "extern" use for?
 *
 * 1, extern
 *
 * 1,1), Normally, we should compile "main.c" and "stack.c" together 
 * because some functions of "stack.c" are used in "main.c". If we
 * only input "gcc -Wall -c main.c", there will be warnings not errors.
 * 
 *     "warning: implict declaration of function..."
 *
 * The compiler declared these functions in an underlying way but the 
 * parameters are not as same as those in "stack.c".
 *
 *
 * 1.2), In "main.c" we should use "extern" to delcare these external functions
 * to clearify that they are outside so that the compiler would be able to 
 * find them.
 *
 * Note: if "main.c" and "stack.c" are compiled together, the "extern" can be
 * ommitted.
 *
 * 2, static
 * If a variable or a function were modified by "static", it could not be used
 * or called outside of the source where it is.
 * It just like "Internal Linkage".
 * See stack.c.
 *
 * When we are compiling "stack.c" and "main.c" together-"gcc stack.c main.c", 
 * there is an error-undefined function "list" even if we add "extern" before 
 * "list(..)".
 *
 *
 * */

int a, b = 1;

extern void push(char); // The compiler is informed of the type of parameters.	
extern char pop(void);
extern int is_empty(void);

extern int list(int);  //

int main(void)
{
	push('a');
	push('b');
	push('c');

	while(!is_empty()){
		putchar(pop());
	}

	putchar('\n');

	list(1);

	return 0;

}

