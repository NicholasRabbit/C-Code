# include<stdio.h>
# define N 8
/*
 * Merge Sort
 * */

int arr[N] = {8,7,6,5,4,3,2,1};

int merge(int begin, int mid, int end){

	int i = begin;
	int j = mid + 1;

	//A temprorary array
	int tempArr[N] = {0,};
	//temprorary index
	int t = 0; 

	while(i <= mid && j <= end){
		
		if(arr[i] < arr[j]){
			tempArr[t] = arr[i];
			i ++;
			t ++;
		}else{
			tempArr[t] = arr[j];
			j ++;
			t ++;
		}
	}

	//If there were still some elements remains on the left array.
	while(i <= mid){
		tempArr[t] = arr[i];
		t ++;
		i ++;
	}
	//right
	while(j <= end){
		tempArr[t] = arr[j];
		t ++;
		j ++;
	}

	
	//Copy elements form tempArr to arr.
	t = 0;
	while(begin <= end){
		arr[begin] = tempArr[t];
		t ++;
		begin ++;
	}


	return 0;
}


//divide
int divide(int begin, int end){
	
	if(begin < end){
		int mid = (begin + end) / 2;
		//Turn left
		divide(begin, mid);
		//Turn right
		divide(mid + 1, end);

		merge(begin, mid, end);
		
	}
	

	return 0;
}


int main(void){

	divide(0,N - 1);
	
	for(int i = 0; i < N; i++){
		printf("%d\n",arr[i]);
	}

	return 0;

}
