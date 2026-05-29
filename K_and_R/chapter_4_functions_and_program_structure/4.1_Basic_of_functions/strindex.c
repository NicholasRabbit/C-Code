#include <stdio.h>
#include <string.h>

// return the first index of "seachfor" if it is found in "source".
int strindex(char s[], char t[])
{
	int i, j, k;

	// The length of s is fixed, don't write the function call, "strlen()", to the condition test.
	//for (i = 0; i < strlen(s); i++) { 
	int len = strlen(s);
	for (i = 0; i < len; i++) {
		for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; j++, k++);
		if (k > 0 && t[k] == '\0') 
			return i;	// return the first index if matched.
	}
	return -1;
}
