#include <stdio.h>

#define N 16

void get_line(char line[])
{
	char c;
	int i = 0;
	while ((c = getchar()) != EOF) {
		line[i++] = c;
	}

	printf("%s\n", line);

}

void do_some()
{
	printf("Hi there!\n");
}

void touch_down()
{
	printf("The program is exploited!\n");
}


int main(int argc, char *argv[])
{
	char line[N];
	get_line(line);
	
	do_some();

	return 0;
}



