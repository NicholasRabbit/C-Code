# include<stdio.h>

/*
 * 结构体的内存布局
 *
 * 对比本代码和02代码在物理空间上的存储布局，学习如何合理的声明不同数据类型的变量。
 *
 * 详细笔记及图例见本节个人笔记
 *
 * */
int main(int argc, char** argv){
	
	struct{
		char a;
		short b;
		int c;
		char d;
	} s;

	s.a = 1;
	s.b = 2;
	s.c = 3;
	s.d = 4;

	printf("size of struct: %lu\n", sizeof(s));


	return 0;
}
