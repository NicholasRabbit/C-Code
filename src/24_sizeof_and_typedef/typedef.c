# include<stdio.h>

/*
 * typedef用法
 * 表示在原有类型的基础上自己定义一个新的类型。
 * */
int main(void){
	
	/*
	 * 1,这里个人自定义my_size_t这个变量，
	 * 2,使用typedef后，my_size_t表示一种自定义的类型“unsigned long”, 然后可以用它来声明别的变量。
	 * 3,类型名一般用"_t"表示type
	 * */
	typedef unsigned long my_size_t;
	//num就是unsigned long类型的。
	my_size_t num = 0xffbb;
	printf("num = %lu\n", num);

	//"a" is a type of arr_t, which is an array with a constant size of 10.
	typedef int arr_t[10];
	arr_t a;
	//a = {1,2,3,};   // a could not be intialised by using {..}
	a[1] = 55;
	printf("a[]=%d\n", a[1]);



	return 0;
}
