#include <stdio.h>

#define MAXLINE 1000

int get_line(char line[], int max_line);
void copy(char to[], char from[]);

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
	
	if (max > 0)
		printf("%s\n", longest);

	return 0;

}


int get_line(char s[], int lim)
{	
	int i, c;
	// The reason that "i < lim - 1" not "i < lim" is that '\n' should be
	// at s[lim - 1].
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
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
