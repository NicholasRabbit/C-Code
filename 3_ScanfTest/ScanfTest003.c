#include<stdio.h>
/*
 * 多个scanf()方法中对非法输入值的处理范例
 * */
int main(void){

	//1,友好提示
	printf("请输入数字：");
	
	//这时如果输入的值中含有非法字符如:123m等，则第一个scanf()读取完123之后，第二个会读取m,那么打印
	//出来的就是内存中的残留数据
	int i;
	scanf("%d",&i);
	printf("i = %d\n",i);

	/* 解决办法：使用while循环，当输入的不是换行符号时则继续循环，不给下面的scanf()赋值。
	 * getchar()是个内部函数，注意都是小写。
	 * */
	char ch;
	while((ch = getchar()) != '\n'){
		continue;
	}

	int j;

	scanf("%d",&j);
	printf("j = %d\n",j);

	return 0;

}
