# include<stdio.h>
/* 1,scanf(..)表示接收控制台输入的信息，并把接受到的数值赋予对应的内存地址里，用&来表示地址；
 * 2,注意要使用输入控制符，用法和输出控制符一样；
 * 
 * */
int main(void){

	int i;
	printf("请输入...");
	
	//1,scanf("%d",&i);	//&i表示i的地址，“&”是取地址符
	
	//scanf("abc%d",&i);  //如果输入控制符“%d”前有非输入控制符，在终端要原样输入，否则报错
	//如果“%d”后面有其它字符可以不用管，在终端输入“abc123”就可以。
	
	//此函数有返回值，1，代表有输入，0，无输入。
	int ret = scanf("abc%dxy",&i); 

	printf("ret = %d\n",ret);

	printf("i = %d\n",i); //输出控制符不需要加取地址符"&"

	//2,用数组接收字符串的时候不用加&,加了会报错。
	char str[5];
	scanf("%c",str);
	printf("%s\n",str);

	//3,输出控制符里有"\n"的情况见:ScanfLineNext.c

	return 0;
}

