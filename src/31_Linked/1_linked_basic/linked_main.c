# include<stdio.h>

/*
 * Compile two files together.
 * gcc commands:
 *
 * gcc linked_main.c stack.c -o test_linked.out
 *
 * OR 
 *
 * gcc -c linked_main.c
 * gcc -c stack.c
 * gcc linked_main.o stack.o -o test_linked.out
 *
 * */

int a, b = 1;

int main(void)
{
	push('a');
	push('b');
	push('c');

	while(!is_empty()){
		putchar(pop());
	}

	putchar('\n');

	return 0;

}

