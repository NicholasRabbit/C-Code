/*
 * Remove trailing blanks and tabs from each line of input, and to delete
 * entirely blank lines.
 * */

#include <stdio.h>

#define N 128

int get_line(char line[]);

int remove_white_spaces(char line[], int len);


int main(int argc, char *argv[])
{
	char line[N];
	
	int len = get_line(line);

	printf("%s\n", line);

	len = remove_white_spaces(line, len);

	printf("Removed:length = %d,  %s\n", len, line);

	return 0;
}


int get_line(char line[])
{
	int i, c; 
	i = 0;
	while ((c = getchar()) != EOF && c != '\n') {
		line[i] = c;
		i++;
	}

	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return i;
}

int remove_white_spaces(char line[], int len)
{
	int i;
	for (i = len; i > 0; i--) {
		char c = line[i];
		if (c == ' ' || c == '\t' || c == '\n' || c == '\0' || c == EOF)
			continue;
		else 
			break;
	}

	if (i == 0)
		line[i] = '\0';
	else  {
		line[++i] = '\n';
		line[++i] = '\0';
	}

	return i;

}
