#include <stdio.h>

#define TABSTOP 8
#define N 100


void detab(char line[], int length);
int get_line(char line[]);


int main(int argc, char *argv[])
{
	char line[N];
	int len; 
	while ((len = get_line(line)) > 0) {
		printf("length = %d\n", len);
		printf("%s\n", line);

		detab(line, len);
	
	}
	

	return 0;
}


void detab(char line[], int length) 
{
	int i, col;
	char c, de_line[N];

	/*
	 * Note that '\t' in the original array "line" is only one elements taking one slot, but not 4. 
	 * It will be replaced by 4 spaces. 
	 * */
	for (col = 0, i = 0; col < length; col++) {
		c = line[col];
		if (c == '\t') {
			int spaces = 8 - (i % 8);
			int j;
			for (j = 0; j < spaces; j++) {
				de_line[i] = '*';  // I use '*' instead of ' ' to explicitly replace the 'tabstop'.
				i++;
			}

		} else {
			de_line[i] = c;
			i++;

		}
	}

	printf("%s\n", de_line);

}

int get_line(char line[])
{
	int i, c;
	for (i = 0; i < N - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return i;

}



