#include <stdio.h>

#define IN 1
#define OUT 0


int main(void) 
{
	/*
	 * nl: number of lines
	 * nw: number of words
	 * nc: number of characters
	 * */ 
	int c, nl, nw, nc, state;

	state = OUT;
	nl = nw = nc = 0; // This expression equals "nl = (n = (nc = 0))".

	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\t' || c == '\n')
			state = OUT;
		else if (state == OUT) {
			state = IN;
			++nw;
		}

	}

	printf("nl = %d, nw = %d, nc = %d\n", nl, nw, nc);

	return 0;
}
