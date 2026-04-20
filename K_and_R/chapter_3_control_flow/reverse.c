#include <stdio.h>
#include <string.h>

#define N 32

void reverse(char s[])
{
	int c, i, j;
	// 1. j = sizeof(s) - 1. Wrong ! sizeof(s) is the length of the string pointer "s". It should be "strlen(...)".
	// 2. i != j. It is also wrong! It should be "i < j". If the input is even number of string, such as "abcd", i
	//	  will never equals to j.
	//for(i = 0, j = sizeof(s) - 1; i != j; i++, j--) {
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}


void reverse2(char s[])
{
	int c, i, j;
	for(i = 0, j = strlen(s) - 1; i < j; i++, j--) {
		c = s[i], s[i] = s[j], s[j] = c;  // Add commas. 
	}
}


int main(int argc, char *argv[])
{
	
	int i, c;
	char s[N];
	i = 0;
	while (i < N && (c = getchar()) != EOF && c != '\0' && c != '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	// It is not necessary to check the length of the string, because
	// There is a condition, "i < N", in the "while".
	/* 
	if (strlen(s) > 32) {
		printf("Please input a string less than 32.");
		return 1;
	}*/

	//reverse(s);

	reverse2(s);

	printf("Reversed: %s\n", s);

	return 0;
}
