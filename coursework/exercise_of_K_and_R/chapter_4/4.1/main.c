#include <stdio.h>

#define MAXLINE 1000

int get_line(char s[], int lim);
int strindex_rightmost(char source[], char searchfor[]);

char pattern[] = "hello";

int main(int argc, char *argv[])
{
	char line[MAXLINE];
	int right, count = 0;
	while (get_line(line, MAXLINE) > 0) {
		if ((right = strindex_rightmost(line, pattern)) > 0) {
			printf("The index of rightmost occureance is %d\n", right);
			count++;
		}
	}

	return right;

}

