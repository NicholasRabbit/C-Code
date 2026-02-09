#include <stdio.h>

#define MAXLINE 1000

int max;
char line[MAXLINE];
char longest[MAXLINE];

<<<<<<< HEAD
int getline(void);
void copy(void);
=======
int get_line();
void copy(void);

int main(int argc, char *argv[])
{

	int len;
	extern int max;
	extern char longest[];

	max = 0;
	while ((len = get_line()) > 0) {
		if (len > max) {
			max = len;
			copy();
		}
	}

	if (max > 0)
		printf("%s\n", longest);

	return 0;
}

int get_line()
{
	int i, c;
	extern char line[];
	for (i = 0; i < MAXLINE - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
		line[i] = c;
	}

	if (c == '\n') {
		line[i] = c;
		i++;
	}

	line[i] = '\0';

	return i;

}

void copy()
{
	int i;
	extern char line[], longest[];
	i = 0;
	while((longest[i] = line[i]) != '\0')
		++i;
}
>>>>>>> c9e61d24e0e85fd3c9b2ce31421a880f5908bb05
