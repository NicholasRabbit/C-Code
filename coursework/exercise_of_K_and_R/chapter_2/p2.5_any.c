#include <stdio.h>

#define N 32
#define TMAX 128

// The complexity of time of the following function is O(n^2).
// After reading the source code of "strpbrk", I optimise this function
// by imitating it. 
int any(char *s1, char *s2)
{
	int i, j;
	char c, d;
	for (i = 0; (c = s1[i]) != '\0'; i++) {
		for (j = 0; (d = s2[j]) != '\0'; j++) {
			if (s1[i] == s2[j])
				return i;
		}
	}

	return -1;
}


/*
 * How to optimise ? 
 * 1. Create a table, t[128], with the size of 128 and use the integer value of characters as its index.
 *	  Set the default value of each element to -1.
 * 2. Iterate s1[] and set the matched object to the index of the element in s1[], namely t[s[i]] = i.
 * 3. If any of the element in s2[] is found, return the t[index], which is the value of the index in s1[].
 *
 * In conclusion, the complexity is O(n).
 * */
int any_optmise(char s1[], char s2[])
{
	char c, t[TMAX];
	int i;
	for (i = 0; i < TMAX; i++)
		t[i] = -1;
	i = 0;
	while ((c = s1[i]) != '\0') {
		t[(int)s1[i]] = i;
		i++;
	}
	
	for (i = 0; i < TMAX; i++) {
		if (t[i] != -1)
			printf("t[%d] = %d\n", i, t[i]);
	}

	for (i = 0; i < N; i++) {
		int index;
		if ((index = t[(int)s2[i]]) != -1)
			return index;
			

	}

	return -1;

}


int main(int argc, char *argv[])
{


	char s1[N] = {'a', 'h', 'i'}; 
	char s2[N] = {'x', 'b', 'h'};
	//int result = any(s1, s2);
	int result = any_optmise(s1, s2);
	printf("%d\n", result);

	return 0;
}
