# include<stdio.h>
/*
 *使用if把输入的三个数从小到达排序
 * */
int main(void){
	
	//输入提示
	printf("请输入3个数字,用空格隔开，系统将从下到达排序：");
	
	int a,b,c;

	scanf("%d %d %d",&a,&b,&c);

	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}
	if(b > c){
		int temp = b;
		b = c;
		c = temp;
	}
	if(a > b){
		int temp = a;
		a = b;
		b = temp;
	}

	printf("%d,%d,%d\n",a,b,c);
	
	return 0;
}
