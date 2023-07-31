# include<stdio.h>

/*
 * C中的函数调用
 *
 * 1,函数的相关概念
 * 函数返回值类型，函数名称，形参类型和个数总称为“函数原型”;
 * 后面大括号及其内部的语句称为"函数体"。
 * “函数原型”和“函数体”合起来称为函数定义，即定义了一个函数。
 *
 * 3,C中可以只写函数原型，称为“函数声明”，后面写了函数体才称为“函数定义”。
 * 类似于Java中的抽象函数及其实现方法的原理。
 *
 * 4,C中的函数书写顺序:
 * 函数声明必须写在其调用者之前。 注意和Java中不同！
 * 写在其后编译有警告，运行也可以通过，但是后期容易出bug，不建议这样写。
 * 运行通过的原因：
 * 在main函数中调用addAfter(..)时
 *
 * 5,还有一种C编译器默认给调用的函数设定返回值类型，形参的分析，见DefinedFuncation2.c
 * */


//函数必须写在其调用者之前。
int add(int i,int j){
	
	printf("i+j=%d \n",i+j);

	return i + j;

}

int main(void){

	printf("main function execute!\n");
	//add(10,15);
	addAfter(12,17);

	return 0;
}

//方法写在main之后，编译报警: warn:implicit declaraion...,但可以运行
int addAfter(int i,int j){
	
	printf("i+j=%d \n",i+j);

	return i + j;

}




