#include <stdio.h>

#define N 32

void squezze_alter(char s1[], char s2[]);
int get_line(char line[]);


int main(int argc, char *argv[])
{
	char s1[N], s2[N];
	get_line(s1);
	get_line(s2);

	squezze_alter(s1, s2);
	printf("s1 is %s\n", s1);

	return 0;
}

void squezze_alter(char s1[], char s2[])
{
	int i, j, k, len1, len2;
	len1 = 0;
	while (s1[len1] != '\0')
		len1++;
	len2 = 0;
	while (s2[len2] != '\0')
		len2++;

	for (i = j = 0; i < len1; i++) {
		int flag = 0;
		for (k = 0; k < len2; k++) {
			if (s1[i] == s2[k]) {
				flag = 1;
				break;
			}

		}

		if (!flag) {
			s1[j] = s1[i];
			j++;
		}
	}
	s1[j] = '\0';
}

int get_line(char line[]) 
{
	int i = 0, c;

	printf("Please input a line: ");
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
