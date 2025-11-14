#include <stdio.h>

char * get_cp(char *cp)
{
	cp = "abc";
	return cp;
}


int main(int argc, char *argv[])
{
	char *cp = " ";
	get_cp(cp);

	return 0;
}
