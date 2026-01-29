#include <stdio.h>

#define MAXLINE 16


int get_line(char s[]);
int get_line2(char s[], int len);
void reverse(char arr[], int len);

int main(int argc, char *argv[])
{
	int len;
	char s[MAXLINE];

	//get_line(s);

	while ((len = get_line2(s, MAXLINE)) > 0) {

		printf("length = %d\n", len);
		printf("%s\n", s);
	
		// To reverse
		reverse(s, len);
		printf("Reversed: %s\n", s);

	}



	return 0;
}


/*
 * The following "get_line" is buggy. 
 * 1. The local variable "i" is not intialised. 
 * 2. It hasn't verified the length of the array, which might be overflow. 
 * */
int get_line(char s[])
{
	int i, c; 
	while ((c = getchar()) != EOF && c != '\n') {
		s[i] = c;
		i++;
		if (i == (MAXLINE - 1))
			break;
	}

	if (c == '\n') {
		s[i] = c;
		i++;
	}

	s[i] = '\0';

	return i;
}

int get_line2(char arr[], int len)
{
	int i, c;

	for (i = 0; i < len - 1 && (c = getchar()) != EOF && c != '\n'; i++) 
		arr[i] = c;

	if (c == '\n') {
		arr[i] = c;
		i++;
	}

	arr[i] = '\0';

	return i;
}

/*
 * Reverse an char array.
 * 1. Switch the first element and the last one in the array;
 * then the second one and the second to the last...
 * Increment the smaller index by 1 and decrement the larger index by 1.
 *
 * 2. If and only if the smaller index is larger than than the larger one, 
 * stop switching.
 *
 * */
void reverse(char arr[], int len) 
{
	int head, tail;
	head = 0;
	tail = len - 2;  // Don't switch the '\n' at the index of "len - 1";

	char temp = ' ';
	while (head < tail) {
		temp = arr[head];
		arr[head] = arr[tail];
		arr[tail] = temp;

		head++;
		tail--;
	}

	
}


