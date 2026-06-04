#include <stdio.h>

/*
 * A general version of atoi. 
 * It is different from the example in the book in page 61.
 * I will modify it later.
 * */

int atoi(char s[]) 
{
	int i, sign, num;
	for (i = 0; s[i] == '-'; i++)
		;
	sign = (s[0] == '-') ? -1 : 1;
	
	num = 0;
	for (; s[i] != '\0'; i++) {
		num = num * 10 + (s[i] - '0');
	}

	return num * sign;

}


int main(int argc, char *argv[])
{
	char *s = "-123";
	int num = atoi(s);
	printf("%d\n", num);
	return 0;
}
