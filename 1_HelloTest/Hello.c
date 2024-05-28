
/*
 * #include..表示引入外部库
 * C语言引入的外部库的目录是/usr/include
 * 使用printf()函数需要引入stdio.h，不引入也不报错，但是程序中只能写int i;这样的声明语句，
 * 不能调用该函数了。
 * 关于引入文件的解释详见个人笔记。
 * */

#include <stdio.h>

int main(){
	printf("Hello C! \n");
	return 0;
	
}
