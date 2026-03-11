#include <stdio.h>

#define MAX 8


void get_line(char s[], int lim)
{
	int i, c;
	for (i = 0; i < lim - 1 ; i++) {
		c = getchar();
		if (c == '\n')
			break;
		if (c == EOF)
			break;
		s[i] = c;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	printf("%s\n", s);

}


int main(int argc, char *argv[])
{
	
	char line[100];
	get_line(line, MAX);


	return 0;
}
