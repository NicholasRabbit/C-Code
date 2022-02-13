//一次使用多个输入控制符，即用键盘输入多个值
# include <stdio.h>
int main(void){
	int i;
	int j;
	//scanf("%d %d",&i,&j);	//有多个输入控制符就在终端输入多个数值，注意中间有空格输入非输入控制符也要原样输入
	scanf("%d,%d",&i,&j);   //这里逗号也是非输入控制符，要原样输入
	printf("i=%d\nj=%d\n",i,j);

}
