#include <stdio.h>

int main(int argc, char *argv[])
{
	double sum;
	char line[8];
	sum += atof(line);	// An implicit declaration of "atof()", because before "main" it has been delcared yet.

	int acc = 0;
	acc += atoi(line);

	return 0;
}

//double atof(char s[])
int atof(int i)		// The argument is different, but it doesn't cause any errors. 
{
	return 0;
}
