# include<stdio.h>

# define LEN 5

/*
 * insertion sort
 * */

int arr[LEN] = {3,26,18,2,5};

int insertion_sort(){

	for(int index = 1; index < LEN; index ++){
		int insetVal = arr[index];
		int i = index - 1;
		while(i >= 0 && insetVal < arr[i]){
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i + 1] = insetVal;
	}

	//iterate
	for(int i = 0; i < LEN; i++){
		printf("%d,",arr[i]);
	}

	return 0;
}

int main(void){

	insertion_sort();

	return 0;
}
