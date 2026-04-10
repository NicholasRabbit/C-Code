#include <stdio.h>

#define N 32

void escape(char *s, char *t)
{
	int i = 0, j = 0;
	char c;
	while ((c = *(t + i)) != '\0') {
		switch (c) {
			case '\n': 
				s[j++] = '\\';  // s[j] = '\\'; j++;
				s[j++] = 'n';
				break;
			case '\t':
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = c;
				break;
		}
		i++;
	}

	printf("%s\n", s);
}


int main(int argc, char *argv[])
{
	
	char *t = "abc\td\nxyz";
	char s[N];

	escape(s, t);

	return 0;
}
