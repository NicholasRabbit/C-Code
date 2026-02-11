#include <stdio.h>

#define TABSTOP 8
#define N 100

/*
 * As tab stops every 8 columns, it should be inserted if there are blanks between the last non-blank character and
 * the next tabstop. To illustrate, in "abcxxxxxH" the five spaces, represented with "x", should be replaced by a tab.
 * If there aren't any spaces between the last non-blank character and the next tabstop, we should not add any tabs.
 * As an illustartioin, in "abxxijklH" there is no spaces between l and H, therefore, don't add any tabs even though
 * there are two spaces following "ab".
 * */

char line[n];
char en_line[N];

void entab(char line[], int length);


int main(int argc, char *argv[])
{
	char *s = "a\tbc";
	
	printf("%s\n", s);

	return 0;
}

/*
 * To tackle this problem, I use two variables as indexs: col and i.
 * "col" is set to the index of the first space ' ' of one iteration and "i" is used find the first
 * non-blank character after this space. If and only if "i % 8 == 0", which indicates that there are before the next tab stop, 
 * we should replace the space at "col"  with a tab stop.
 *
 * */
void entab(char line[], int length)
{
	int col, i, space_flag;
	char c;
	space_flag = 0;
	
	for (col = 0, i = 0; i < length; i++) {
		c = line[i];
		if (c != ' ') {
			en_line[col] = c;
			col++;
		} else if (c == ' ') {
			col = i;
		}

		// Keep on iterating.
		if (c)

	}

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



