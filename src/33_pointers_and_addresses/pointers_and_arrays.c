#include <stdio.h>

int main(int argc, char *argv[])
{
	char *s1 = "bye", *s2 = "Hello world!";

	int i = 0;
	while (argv[i] != '\0')
		i++;
	
	argv[i++] = s1;
	argv[i++] = s2;
	argv[i++] = '\0';

	printf("%s\n", argv[3]);
	

	return 0;
}
