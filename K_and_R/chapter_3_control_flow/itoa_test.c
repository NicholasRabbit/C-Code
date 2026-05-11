#include <stdio.h>
#include <string.h>

#define N 16

void reverse(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}

/*
 * Convert a number to a character string.
 * */
int itoa(int n, char s[])
{
	int i, sign;
	if ((sign = n) < 0)
		n = -n;
	i = 0;
	do {
		s[i++] = n % 10 + '0';
		
	} while ((n /= 10) > 0);  // '/' is the division sign.
	
	if (sign < 0)
		s[i++] = '-';
	
	s[i] = '\0';

	reverse(s);
	printf("%s\n", s);

	return 0;

}


int main(int argc, char *argv[])
{
	
	int num;
	char s[N];
	int i = 0;
	for (i = 0; i < N; i++)
		s[i] = 0;

	scanf("%d", &num);
	itoa(num, s);

	return 0;
}
