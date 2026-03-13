#include <stdio.h>

#define MAX 8

/*
 * At the first glimpse of "atoi", I am confused why why n = 10 * n, therefore,
 * I review it even though I understand it now.
 * */
int atoi(char s[])
{
	int i, n;
	n = 0;
	for (i = 0; s[i] >= '0' && s[i] <= '9'; i++)
		n = 10 * n + (s[i] - '0');

	return n;
}


int get_line(char line[])
{

	int i, c;
	i = 0;
	// The last character is '\0', so "i < MAX - 1". 
	while (i < MAX - 1 && (c = getchar()) != '\n' && c != EOF) {
		line[i] = c;
		i++;
	}

	if (c == '\n') {
		line[i++] = c;
	}

	line[i] = '\0';

	return i;
}


int main(int argc, char *argv[])
{
	char line[MAX];
	int number = get_line(line);
	
	printf("The line is %s\n", line);
	printf("The number is %d\n", number);

	int i = atoi(line);
	printf("The integer is %d\n", i);

	return 0;

}
