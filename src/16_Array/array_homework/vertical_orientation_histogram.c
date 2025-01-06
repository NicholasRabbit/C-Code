#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the array
#define N 20

// Define the range of the numbers
#define MIN 0
#define MAX 9

// Define the symbol for the histogram
#define SYMBOL '*'

//8.3. homework


// Declare an array of integers
int arr[N];

//Generate an array of which all the elements are random numbers.
int genRandom(int upperBound){
	// Initialize the random number generator.
	srand(time(NULL));

	// Assign each element of the array with a random number between MIN and MAX
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % (MAX - MIN + 1) + MIN;
	}

	return 0;

}

// Count how many times each number appears in the array
int howMany(int count[]){
	
	// Print the array
	printf("The array is:\n");
	for (int i = 0; i < N; i++) {
		printf("%d ", arr[i]);
	}

	printf("\n");

	for (int i = 0; i < N; i++) {
		count[arr[i] - MIN]++;
	}

	return 0;
}



int main(){

	genRandom(MAX - MIN + 1);

	// Declare a variable to store the count of each number
	int count[MAX - MIN + 1] = {0};
	howMany(count);

	// Print the histogram
	printf("The histogram is:\n");
	printf("0 1 2 3 4 5 6 7 8 9\n");
	printf("\n");

	// Find the maximum count
	int max_count = 0;
	for (int i = 0; i < MAX - MIN + 1; i++)
	{
		if (count[i] > max_count)
		{
			max_count = count[i];
		}
	}

	// Print the symbols for each count from top to bottom
	for (int i = 0; i <= max_count; i++)
	{
		for (int j = 0; j < MAX - MIN + 1; j++)
		{
			//Use gerater symbol here, because we want to print the count which is greater than zero.
			//Then the next row we should print any element which is greater than 1, so does the rest rows.
			if (count[j] > i)
			{
				printf("%c ", SYMBOL);
			}
			else
			{
				printf("  ");
			}
		}
		printf("\n");
	}

	return 0;
}
