#include<stdio.h>


/* 
 * C语言编码风格总结：
 * 1，尽可能参照Linux的《Coding Style》
 * 2, C中标识符不要用驼峰的形式，统一用下划线
 * 3, indent 命令统一整理编码风格,在CLI界面执行，此命令不建议过度使用，好的代码应在编写阶段就保持好的规范格式。
 *    indent -kr -i8 CodingStyle.c
 *    -kr表示使用K&R的风格
 *    -i8表示缩进8位字符
 * 
 * */

/*
 * 一，注释书写格式：
 * 1，多行注释，内容和*间间隔一个字符；
 * 2，注释块内第一行不写任何内容；
 * */

/*
 * 二，编码格式：
 * 参照下面范例。
 * 
 * */


//1，函数声明单独一行，形参之间用空格隔开。
int do_some(int i, int j)
{
	int k = i + j;		//实际缩进要求是8个字符，个人习惯是4个，待改进.

	switch (i) {

	case 1:		//case要求和switch同位置缩进，但是vi编辑器自动缩进，待确认。
		k = i - j;
		break;  //执行indent后就自动按照K&R风格对齐了。
	case 2:
		k = i % j;
		break;
	default:
		k = 0;
		break;

	}

	return k;		//return 前面必须有一个空行。
}


int main(void){

	int ret = do_some(1, 29);
	printf("%d\n",ret);

	return 0;

}
