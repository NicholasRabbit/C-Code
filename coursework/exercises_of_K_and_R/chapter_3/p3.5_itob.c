#include <stdio.h>
#include <string.h>

#define N 32


void reverse(char *s)
{
	int i, j, c;
	for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
		c = s[i], s[i] = s[j], s[j] = c;
}


void itob(int n, char *s, int base)
{
	int i, r, sign;
	
	// I don't deal with the minimum negative number of two's complement for now. 
	if ((sign = n) < 0)
		n = -n;

	/* 1. Convert an integer into hexadecimal number. 
	 * As converting decimal numbers into binary ones, we also need remainders of each division.
	 * */
	i = 0;
	if (base == 16) {
		// Since the conversion must be done at leat once even the number is 0, I use "do...while".
		do {
			// 1.1 If the remainder is less than 10, which is represented by 'c' in hexadecimal numbers.
			r = n % 16;
			if (r < 10)
				s[i++] = r + '0';
			else if (r >= 10) 
				s[i++] = r - 10 + 'a';

		} while ((n /= 16) > 0);
		s[i++] = 'x';
		s[i++] = '0';

	} else if (base == 8) {
		/*
		 * 2. Octal number
		 * */
		do {
			s[i++] = n % 8 + '0';
		} while ((n /= 8) > 0);
		s[i++] = '0';	// Octal numbers start with 0.
	} else if (base == 2) {
		/*
		 * 3. Binary numbers.
		 * */
		do {
			s[i++] = n % 2 + '0';
		} while ((n /= 2) > 0);
		s[i++] = 'b';
		s[i++] = '0';	// Binary numbers start with "0b".
	}

	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';

	reverse(s);
	printf("%s\n", s);
}


int main(int argc, char *argv[])
{
	char s[N];
	itob(-123, s, 16);
	itob(-123, s, 8);
	itob(-123, s, 2);

	return 0;

}
