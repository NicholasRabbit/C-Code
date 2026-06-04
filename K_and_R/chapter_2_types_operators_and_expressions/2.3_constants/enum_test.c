#include <stdio.h>

/*
 * 1. If not specified, the first element in an enum has value of 0.
 * */
enum boolean {NO, YES};

/*
 * 2. If an element is asigned with a value, the following ones will increment by 1.
 * */
enum weeks {MONDAY = 1, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY, SUNDAY};

/*
 * 3. Elements in an enum can be assigned with characters, which are literally integers.
 * */
enum escapes {BELL = '\a', BACKSPACE = '\b', TAB = '\t',
				NEWLINE = '\n', VTAB = '\v', RETURN = '\r'};


int main(int argc, char *argv[])
{
	printf("%d, %d\n", NO, YES);

	printf("%d, %d\n", TUESDAY, WEDNESDAY);

	printf("%c %c %c %c %c %c", BELL, BACKSPACE, TAB, NEWLINE, VTAB, RETURN);
		

	return 0;
}
