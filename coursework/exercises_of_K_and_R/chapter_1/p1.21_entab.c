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

char line[N];
char en_line[N];

void entab(int len);
int get_line(void);


int main(int argc, char *argv[])
{
	int len = get_line();
	entab(len);

	return 0;
}

/*
 * To tackle this problem, I use two variables as indexs: col and i.
 * "col" is set to the index of the first space ' ' of one iteration and "i" is used find the first
 * non-blank character after this space. If and only if "i % 8 == 0", which indicates that there are spaces before the next tab stop, 
 * we should replace these spaces at "col"  with a tab stop.
 *
 * */
void entab(int length)
{
	int col, i, j, non_space;
	char c;
	non_space = 0;
	
	for (col = 0, i = 0; i < length; i++, col++) {
		if (col % 8 == 0)  {
			// Check backwards.
			int temp = col - 1;
			for ()
		}

	}

	printf("%s\n", en_line);

}


int get_line()
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



