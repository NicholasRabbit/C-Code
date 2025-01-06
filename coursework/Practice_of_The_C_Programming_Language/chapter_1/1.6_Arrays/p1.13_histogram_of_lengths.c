#include <stdio.h>

#define N 1000

// Without using any array.
int horizontal_histogram() 
{
	int c, count, i;
	count = 0;
	while ((c = getchar()) != EOF) {
		/*
		 * Don't write "if (c != '' || c != '\n' || c != ''t')" because
		 * the condition is always true. If c doesn't equals ' ' it 
		 * might equals '\n' so the statement will be executed.
		 * */
		if (c != ' ' && c != '\n' && c != '\t') {
			putchar(c);
			count++;
		} else {
			// To align symblos in every row in the histogram.
			for(i = 0; i < (10 - count); i++)
				putchar(' ');

			putchar(':');
			for (i = 0; i < count; i++)
				putchar('#');
			putchar('\n');
			count = 0;
		}

	
	}
	

	return 0;
}


/*
 * To implement the requirement of printing a histogram with using an array.
 *
 * */
int horizontal_histogram_with_array() {

	int i, count, word_count, c, n_character[N];

	// To initialise the array.
	for(i = 0; i < N; i++)
		n_character[i] = 0;

	count = 0;
	i = 0;
	while((c = getchar()) != EOF) {
		// c is a character but not a white space.
		if (c != ' ' && c != '\n' && c != '\t'){
			++count;
		} else {
			if (count > 0) {
				n_character[i] = count;
				count = 0;
				++word_count;
				++i;
			}
		
		}
	}

	for (i = 0; i < word_count; i++) {
		int j;
		for (j = 0; j < n_character[i]; j++)
			putchar('#');
		putchar('\n');
	}
	
	return 0;
}



int main(void) 
{
	
//	horizontal_histogram();
	horizontal_histogram_with_array();

	return 0;
}
