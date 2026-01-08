#include <stdio.h>

#define MAXLINE 100

int get_line(char line[], int max_line);
void copy(char to[], char from[]);


int main(int argc, char *argv[])
{

	int len, max; 
	char line[MAXLINE], longest[MAXLINE];
	max = 0;
	while ((len = get_line(line, MAXLINE)) > 0) {

		if (len > max) {
			max = len;
			copy(longest, line);
		}

		if (len > 80)
			printf("A line is longer than 80: %s\n", longest);
		
	}

	if (max > 0)
		printf("longest: %s\n", longest);
	return 0;
}


int get_line(char s[], int lim) 
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
			s[i] = c;
	
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return i;

}

void copy(char longest[], char line[]) 
{
	int i;
	for (i = 0; (longest[i] = line[i]) != '\0'; i++);

}
