# include<stdio.h>

/*
 * 嵌套循环
 * 打印99乘法表
 * */
int loop(int n){
	
	int i;
	for(i = 1; i <= n; i++){
		int j;
		for(j = 1; j <= i; j ++){
			printf("%d\t",i * j);
		}
		printf("\n");
	}

	return 0;
	

}


int main(void){

	loop(9);

	return 0;
}
