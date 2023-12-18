# include<stdio.h>


/*
 * sizeof is a special operator.It has two different forms. They are "sizeof expression" and "sizeof (...)".
 * As its name, it return the byte's size of its parameter.
 * */
int main(void){
	
	int arr[10];

	//sizeof 返回值是unsigned long
	
	//返回数组内所占字节的总数，即 4(int所占空间) x 10 = 40
    unsigned long arrSize =  sizeof arr;  
	printf("sizeof arr: %lu\n", arrSize);
	
	//返回数组的容量，第一个元素的容量，即4 bytes
    unsigned long arrSize0 =  sizeof arr[0];
	printf("sizeof arr0: %lu\n", arrSize0);

	//long所占字节数实际是Implementation Defined，本系统编译器分配的是8字节
	long l;
	unsigned long sizeLong = sizeof l;
	printf("sizeof long: %lu\n", sizeLong);

	

	return 0;
}
