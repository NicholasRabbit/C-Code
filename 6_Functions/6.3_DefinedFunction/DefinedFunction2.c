# include<stdio.h>

/*
 * C语言函数研究-2
 *
 * 编译器指定默认函数的返回值类型，形参列表
 * 当函数在声明之前被调用，编译器就会默认指定返回值类型为int,形参为void(void也是一种数据类型，但不能做运算等)
 *
 * 例：main方法中调用doSome()时，因为其前面没有此函数的声明，因此按默认规则设置为 int doSome(void)
 * 但当执行到下面时看到函数声明是void doSome(),就会报警:conflit types for ...
 * 然后程序仍然可以运行，后期有bug隐患，不建议这样写。
 * 
 * */
int main(void){

	doSome();  //complier default setting: int doSome(void)
	return 0;
}

//返回值类型定义为void,跟默认的不同。
void doSome(){
	printf("doSome execute! \n");
}
