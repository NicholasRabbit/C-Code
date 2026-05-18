#include <stdio.h>
#include <string.h>

#define N 32

/*
 * I have fixed the bug that the code can't convert the minimum negative number 
 * 0x8000 0000 to a appropriate string.
 * Currently, the program is cluttered and is to be optimised later. 
 * */

void reverse(char *s)
{
	int c, i, j;
	for (i = 0, j = strlen(s) - 1; i < j;  i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;
	}
	s[strlen(s)] = '\0';
}

/*
 * Convert an integer to characters in s[].
 * */
void itoa(int n, char *s)
{
	int i, sign;
	unsigned ui;
	
	// The minimum negative number
	// For example, in most cases, 1 << 31 when the size of int is 4 in a machine.
	int min_neg = 1 << (sizeof(int) * 8 - 1);
	if (min_neg == n) {
		ui = n;
		sign = -1;  // Assign "sign" with a negative number; the -1 indictes is only used to indicate it is negative.
	
	} else if ((sign = n) < 0) {
		ui = -n;
	} else {
		// A positive number.
		ui = n;
	}

	i = 0;
	do {
		s[i++] = ui % 10 + '0';
	} while (ui /= 10);

	if (sign < 0) {
		s[i++] = '-';
	}
	
	s[i] = '\0';

	reverse(s);
	printf("%s\n", s);
}




int main(int argc, char *argv[])
{
		
	//char s[3] = {'a', 'b', 'c'};
	//reverse(3, s);
	//printf("%s\n", s);

	char s[N];

	int n;
	printf("Input an integer:");
	scanf("%d", &n);

	itoa(n, s);

	return 0;
}
