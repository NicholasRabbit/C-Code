#include <stdio.h>

//#define MAXLINE 1000
// Set the size of an array to 10 so that to test the arbitrarily long one. 
#define MAXLINE 10  

int get_line(char line[], int max_line);
void copy(char to[], char from[]);

int main(void) 
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) 
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	
	if (max > 0)
		printf("%s\n", longest);

	return 0;

}


int get_line(char s[], int lim)
{	
	int i, c;
	
	/*
	 * "i < lim - 1" is deleted so that it can print a line
	 * as long as possible. Since C allows programmers to write
	 * exceeding the length of an array, we can get an arbitrarily long
	 * array.
	 * */
	for (i = 0;  (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;  // Here is "i" equal to "lim - 1".
		++i;
	}
	s[i] = '\0';
	return i;

}

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;

}
