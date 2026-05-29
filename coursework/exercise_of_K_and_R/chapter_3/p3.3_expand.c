#include <stdio.h>
#include <string.h>

#define N 27	// 26 letters in the alphabet and a terminal '\0'.
#define MAX 40	// For 26 letters and 10 digits.

// Currently, we expand lower case letters and digits.

void letter();
void letter_and_digit();
void expand(char *s1, char *s2);
char next_letter(int start, char *s);
char last_letter(char *s);

int main(int argc, char *argv[])
{

	letter();

	return 0;
}

void letter()
{
	//char *s1 = "a-z";
	//char *s1 = "c-t";
	//char *s1 = "d-c-t";
	
	char s2[27];
	//expand(s1, s2);
	
	char *s1 = "-a-z--**";
	char c1 = next_letter(0, s1);
	char c2 = last_letter(s1);
	char s11[3];
	s11[0] = c1;
	s11[1] = c2;
	s11[2] = '\0';
	expand(s11, s2);
	
	
}

void letter_and_digit() 
{
	
	char *s1 = "a-z0-9";
	char s3[MAX];
	char next = next_letter(1, s1);
	printf("next char is %c\n", next);
}

/*
 * 1. Frist of all, expand the simplest shorthand notations like a-z to "abc...z".
 * 2. Then expand notations like "a-b-c". Since we have got the last letter of a string,
 *    it works well with the second case. 
 * 3. The third case is to expmand notations like "a-z0-9".
 *	  3.1 We should find the second letter;
 *	      Then use the method in step 1 to get a complete list of letters.
 *	  3.2 Find the first digit and the second digit.
 *	      Then use the method in step 1 to get a complete list of digits.
 *	  3.3 Joint them.
 *
 * */
void expand(char *s1, char *s2) {

	int len = strlen(s1);
	int gap = s1[len - 1] - s1[0];

	int i;
	for (i = 0; i <= gap; i++) {
		s2[i] = s1[0] + i;
	}	
	s2[i] = '\0';

	printf("s2: %s\n", s2);

}

char next_letter(int start, char *s)
{
	if (start < 0)
		return '\0';
	
	char c;
	while ((c = s[start]) < 'a' || c > 'z')
		start++;

	return s[start];

}

char last_letter(char *s)
{
	char c;
	int len = strlen(s);
	int i = len - 1;
	while((c = s[i]) < 'a' || c > 'z')
		i--;

	return s[i];

}
