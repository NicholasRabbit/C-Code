# include<stdio.h>
/*1,scanf(..)表示接收控制台输入的信息
 *2,注意要使用输入控制符，用法和输出控制符一样
 * */
int main(void){
	int i;
	printf("请输入...");
	//scanf("%d",&i);	//&i表示i的地址，“&”是取地址符
	//scanf("abc%d",&i);  //如果输入控制符“%d”前有非输入控制符，在终端要原样输入，否则报错
	scanf("abc%dxy",&i);  //如果“%d”后面有其它字符可以不用管，在终端输入“abc123”也可以。
	printf("i = %d\n",i); //输出控制符不需要加取地址符"&"

	return 0;
}

