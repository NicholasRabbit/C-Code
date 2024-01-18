# include<stdio.h>


/*
 * C语言字符串
 * 在C中没有String这个关键字，字符串是以char数组的形式表示的。
 * */

int main(void){
	
	/* 一，初始化
	 * 1,字符数组的初始化，每个字符占有一个元素;
	 * 2,底层实际是：H | e | l | l | o | \0 |，这几个字符依次给数组初始化赋值,
	 *   最后一个\0是八进制，编译器默认给的，表示Null,称为Null-ternimated String, 代表着字符串的结束,
	 *   Null本身是Non-printable字符，即什么也不打印。
	 * 3,后面四个未赋值的编译器也默认赋值\0,即Null。
	 * */
	char str[10] = "Hello"; //相当于： char str[10] = {H,e,l,l,o,\n};
	char str1[5] = {'a','w','e','f'};
	int i;
	for(i = 0; i < 5; i ++)
		printf("str1[%d]: %c\n",i,str1[i]);  //测试最后一个"\0"打印什么。

	// 4, "Hello"是字符串字面值,是只读的，不等同于 str这样的变量名。
	//	  使用"Hello"[0]的形式可以读取该位置的元素值，但是不能改。
	//    但是相同之处是：字符串字面值作为右值时自动转为指向首元素的指针，和数组变量一样。
	char h = "Hello"[0];
	"Hello"[0] = "J";  //warn: assignment of read-only location xxx[0]

	/* 二，字符数组越界的情况
	 * 如果右边的字符串字面值的长度超过数组，编译阶段会报警数组越界。
	 * */
	char str2[5] = "abcdefg";
	printf("str2=%s\n",str2);  //注意：越界的数组只输出数组范围内的5个字符。

	// 1,不指定数组容量，让编译器自动计算长度，可避免越界报警;
	char str3[] = "Hello,world!";

	/* 三，有一种特殊情况，编译器不报警，就是字符串长度刚好和数组长度一致，但是“\0”刚好越界，这样编译器也不报警。
	 * C编译委员会解释为方便程序员，实际这种情况很危险，printf()或其它函数访问此字符数组的时候就会越界，
	 * 有时打印乱码，有时没错，很诡异。应多注意。
	 *
	 * */
	char str4[5] = "Hello";

	printf("str4: %s\n",str4);

	/* 四，输出控制符，用 %s
	 *
	 * */
	printf("str: %s,str2: %s,str3: %s\n",str,str2,str3);

	/* 五，char[]数组也是一样按照数组规定，初始化后不可用{...}的形式赋值，“World”等同于{...}
	 * */
	char str5[10];
	//下行报错，参照：一，4
	str5 = "World";  // error: incompatible types when assigning to type ‘char[10]’ from type ‘char *’,
	





	return 0;
}
