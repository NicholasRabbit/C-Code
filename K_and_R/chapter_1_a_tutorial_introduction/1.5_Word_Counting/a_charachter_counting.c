#include <stdio.h>


/*
 * To input 'EOF' in CLI needs to press 'Ctrl + D',
 * */

int while_loop() 
{
	long nc;
	nc = 0;
	while (getchar() != EOF) 
		++nc;

	printf("%ld\n", nc);

	return nc;
}


int for_loop() 
{
	double nc;
	nc = 0;
	for (;getchar() != EOF; ++nc)
		;  
	// if there is no statement in a for loop a semicolon should be added at the end of the line.

	printf("%.0f\n", nc);

	return nc;
}


int main(void) 
{
	while_loop();

	for_loop();

	return 0;

}
