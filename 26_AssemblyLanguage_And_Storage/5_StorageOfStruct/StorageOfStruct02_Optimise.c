# include<stdio.h>

/*
 * 02这里变量声明顺序和01不同，这里的写法减少了不必要的填充，节省了存储空间。 
 * The RAM space was saved due to the adjustment of the order of declared variables.
 * */
int main(int argc, char** argv){
	
	struct{
		char a;
		char d;  //两个char挨着声明
		short b;
		int c;
	} s;

	//It is not important that the order of assignment, but the order of declaration of the variavles is.
	s.a = 1;
	s.d = 4;
	s.b = 2;
	s.c = 3;

	printf("size of struct: %lu\n", sizeof(s)); //占用空间结果是8 bytes，比01中的12少。


	return 0;
}
