# include<stdio.h>

# define N 10

int arr[N] = {1,2,3,4,5,6,7,8,9,10};


/*
 * To implement binary search in C.
 * */
int binary_search(int num){
	
	int len = N;
	int begin = 0;
	while(begin <= len){
		int mid = (begin + len) / 2;
		if(arr[mid] > num){
			len = mid - 1; 
		}else if(arr[mid] < num){
			begin = mid + 1;
		}else{
			return mid;
		}
	}

	return -1;
}

//Recursion
int recursion_binary(int num, int begin, int len){

	if(begin > len)
		return -1;

	int mid = (begin + len) / 2;

	if(arr[mid] > num)
		return recursion_binary(num, begin, mid - 1);
	else if(arr[mid] < num)
		return recursion_binary(num, mid + 1, len);
	else
		return mid;

}



int main(void){

	printf("Please input:");

	int num;
	scanf("%d",&num);

	int result = binary_search(num);
	printf("result = %d\n",result);

	int index = recursion_binary(num, 0, N);
	printf("index = %d\n",index);

	return 0;
}
