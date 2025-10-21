# include<stdio.h>

int main(void){

	int i,sum;

	char arr[5];

	while(1){
		printf("input:");

		//Don't use &arr, because "arr" is variable of an array and is a pointer. 
		scanf("%s",arr);   

		for(i = 0; arr[i] != '\0'; i++){
			sum = sum * 10 + arr[i] - '0';
		}

		printf("arr = %d\n", sum);
		
	}



	return 0;
}
