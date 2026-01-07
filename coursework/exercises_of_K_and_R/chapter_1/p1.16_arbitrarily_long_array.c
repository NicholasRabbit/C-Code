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
	while ((len = get_line(line, MAXLINE)) > 0) {
		// Bug:
		// The value of "max" will be modified to a large number 
		// when I input characters longer than 10.
		// I haven't figure it out yet after analysing the assembly code. (7 January 2026)
		// Presumably, I will try it later. 
		// printf("max is %d\n", max);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}
	
	
	if (max > 0) {
		// Print the length. 
		// printf("length is %d\n", len);
		printf("%s\n", longest);
	}

	return 0;

}


int get_line(char s[], int lim)
{	
	int i, c;
	
	for (i = 0; (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;  
		++i;
	}
	s[i] = '\0';
	//printf("s[%d] \n", i);
	return i;

}

void copy(char to[], char from[])
{
	int i;
	i = 0;
	while((to[i] = from[i]) != '\0')
		++i;

}
