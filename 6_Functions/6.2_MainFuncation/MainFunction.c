# include <stdio.h>

/*
 * 函数研究
 * C语言中叫函数function, Java中称作方法method
 * */
/*
 * 1,main方法研究
 * 和Java一样，main方法自动被系统调用，是所有程序的入口。
 * 下面的是main的常规写法，当返回值是0时系统判断程序执行成功。
 * 执行出错就返回一个非0值。
 *
 * 获取main函数的返回值的方法:
 * ./BasicFunctin.out : 先执行这条命令
 * echo $? : 再执行这个命令,$?是Shell的一个特殊变量，表示获取上一天命令的退出状态，这里获取到了返回值。
 *
 * */

//C语言中main函数只有两种标准写法：

//main函数第一种写法
/*
int main(void){

	printf("function test \n");

	//return 0;
	return 4;
}
*/

//main函数第二种写法
int main(int argc,char *argv[]){
	printf("second main function. argc==>%d\n",argc);	//输出：argc = 1,原理后期待研究
	return 0;
}
