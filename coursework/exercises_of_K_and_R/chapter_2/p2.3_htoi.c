#include <stdio.h>

#define N 32

int htoi(char s[])
{
	if (s[0] != '0' && (s[1] != 'x' || s[1] != 'X'))
		return 0;
	

	int i, n;
	n = 0;
	

	for (i = 2; s[i] != '\0' && s[i] != '\n'; i++ ) {
		char c;
		if ( (c = s[i]) >= '0' && c <= '9') {
			n = n*(0x10) + (c - '0');
		} else if (c >= 'a' && c <= 'f') {
			n = n*(0x10) + (c - 'a' + 10);
		} else if (c >= 'A' && c <= 'F') {
			n = n*(0x10) + (c - 'A' + 10);
		} else {
			printf("Illegal input: %c\n", c);
			break;
		}

	}

	return n;

}

int get_line(char line[]) 
{
	int i = 0, c;

	while (i < N - 1 && (c = getchar()) != '\n' && c != EOF) {
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
	
	char line[N];
	
	int len = get_line(line);
	int n = htoi(line);
	printf("0x%x\n", n);

	return 0;
}
