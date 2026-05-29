#include <stdio.h>


// counting blanks
int count_blanks() 
{
	int c, nb;
	nb = 0;
	while ((c = getchar()) != EOF) 
		if (c == ' ') 
			++nb;

	printf("blanks are %d\n", nb);

	return nb;
}

// counting tabs
int count_tabs() 
{
	int c, nt;
	nt = 0;
	while ((c = getchar()) != EOF) 
		if (c == '\t')
			++nt;

	printf("tabs are %d\n", nt);

	return nt;

}

// The fucntion to implement counting new lines has been displayed 
// in the code demo so there is not necessary to write duplicated code.

int main(void) 
{

	printf("tabs' value is %d\n", '\t');

	count_blanks();
	count_tabs();

	return 0;

}
