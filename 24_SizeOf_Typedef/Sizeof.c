# include<stdio.h>


/*
 * sizeof is a special operator.It has two different forms. They are "sizeof expression" and "sizeof (...)".
 * As its name, it return the byte's size of its parameter.
 * */
int main(void){
	

	/*
	 * sizeof 计算结果是size_t类型的，这个类型定义在stddef.h文件中，个人推测使用的typedef关键字定义的。
  	 * 但是只要代码中不出现size_t这个变量就不需要引入这个文件。
     * C标准规定size_t是一种无符号整型。
   	 *
	 * 不同编译平台中，size_t的类型不同，因此在个人写代码时不要使用这个size_t作为变量名，
	 * 这样会造成代码不可移植。
	 *
	 * sizeof的结果实际在编译时期就计算出来了。
	 * */
	
	int i = 10;
	unsigned long s = sizeof i;  //The return value of sizeof is unsigned.
	printf("sizeof integer i: %lu\n", s);
	
	//返回数组内所占字节的总数，即 4(int所占空间) x 10 = 40
	int arr[10];
    unsigned long arrSize =  sizeof arr;  
	printf("sizeof arr: %lu\n", arrSize);
	
	//返回数组的容量，第一个元素的容量，即4 bytes
    unsigned long arrSize0 =  sizeof arr[0];
	printf("sizeof int arr[0]: %lu\n", arrSize0);

	//long所占字节数实际是Implementation Defined，本系统编译器分配的是8字节
	long l;
	unsigned long sizeLong = sizeof l;
	printf("sizeof unsigned long: %lu\n", sizeLong);

	
	//sizeof(...) is a function too.
	char c;
	unsigned long sizeChar = sizeof(c);
	printf("sizeof(char): %lu\n", sizeChar);
	
	short sh;
	unsigned long sizeShort = sizeof(sh);
	printf("sizeof(short): %lu\n", sizeShort);

	return 0;

}
