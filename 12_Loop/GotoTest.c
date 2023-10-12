# include<stdio.h>

/*
 * goto demo
 * 用法：中断循环，跳转到goto指定的标识符处，仅在函数范围内起作用，无法跨函数跳转。
 * 平时用的较少，但在特定情况下很好用，结合实际适当使用即可。
 * */
int gotoTest(int n){
	
	int i;
	for(i = 0; i < n ; i++){
		if(i == 5){
			//goto error2;  //无法跳转到函数外
			goto error;
		}
			
		printf("i==>%d\n",i);
	}

	error : printf("go to error %d\n",i);


	return 0;

}

int test(){

	error2 : printf("go to error2");

	return 0;
}

int main(void){

	gotoTest(10);

	return 0;

}
