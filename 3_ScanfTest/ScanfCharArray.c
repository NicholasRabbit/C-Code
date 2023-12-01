# include<stdio.h>

int main(void){

	int i,sum;

	char arr[5];

	while(1){
		printf("input:");
		scanf("%s",arr);   //字符串数组不可用 &arr，否则报错。原因待研究。

		for(i = 0; arr[i] != '\0'; i++){
			sum = sum * 10 + arr[i] - '0';
		}

		printf("arr = %d\n", sum);
		
	}



	return 0;
}
