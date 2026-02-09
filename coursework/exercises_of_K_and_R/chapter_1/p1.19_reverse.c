#include <stdio.h>

#define N 100

void reverse(char reverse[], char origin[]);
int get_line(char s[]);

int main(int argc, char *argv[])
{
	char s[N];

	get_line(s);
	
	printf("%s\n", s);

	return 0;
}


int get_line(char s[])
{
	int i, c; 
	while ((c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		i++;
		if (i == (N - 1))
			break;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return i;
}

void reverse(char reverse[], char origin[]) 
{

}


