#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_line);
void copyt(char to[], char from[]);

int main(void) 
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];

	max = 0;
	while ((len = get_line(line, MAXLINE) > 0)) 
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	
	

	return 0;
}
