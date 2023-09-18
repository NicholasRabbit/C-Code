# include<stdio.h>


/*
 * while demo
 * How many numbers between 1 and 100 which contain 9 ?
 * 1-100的数中含有多少个9？
 * answer: 20
 * */
int loop(int num){
	
	int count = 0;
	int i = 1;
	while(i <= num){

		int temp = i;

		while(temp > 0){
			if(temp % 10 == 9){
				count ++;
			}
			temp = temp / 10; //每个位数都要判断,不止是个位。
		}

		i ++;

	}

	return count;
}



int main(void){
	

	int result = loop(100);
	printf("result==>%d\n",result);


	return 0;
}
