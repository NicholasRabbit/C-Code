#include <stdio.h>

char * get_cp(char *cp)
{
	return cp;
}


int main(int argc, char *argv[])
{
	char *cp = "abc";
	get_cp(cp);

	return 0;
}
