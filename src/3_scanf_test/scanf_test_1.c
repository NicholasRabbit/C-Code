# include<stdio.h>


/* 1,scanf(..)表示接收控制台输入的信息，并把接受到的数值赋予对应的内存地址里，用&来表示地址；
 *
 * 2, scanf("abc%d", &i) and scanf("%d abc", &i)
 *
 *   
 * 3, 注意要使用输入控制符，用法和输出控制符一样；
 *    %d: decimal
 *    %x: hexadecimal
 *    %c: charracter
 * 4, There is no need to use '\n' in 'scanf(...)'. If you did, you should input '\n' on CLI, too.
 *    
 * 
 * */

// 1,scanf("%d",&i);	
// &i表示i的地址，“&”是取地址符
int scanf_func(int i) 
{
	scanf("%d", &i);
	return i;
	
}


// 2,如果输入控制符“%d”前有非输入控制符，在终端要原样输入，否则报错
//   如果“%d”后面有其它字符可以不用管，在终端输入“abc123”就可以。
int fixed_value_input(int i)
{
	scanf("abc%d",&i);  
	return i;
}


// 3, Input data with different type.
// 3.1 input decimal number.
int decimal_func(int i) 
{
	printf("Please i a decimal number: ");
	scanf("%d", &i);
	return i;
}

// 3.2  i hexadecimal number. Note: don't add "0x" before the number.
int hexadecimal_func(int i) 
{
	printf("Please i a hexadecimal number without '0x': ");
	scanf("%x", &i);
	return i;
}

// 3.3 用数组接收字符串的时候不用加&,加了会报错。
char[] char_func() 
{
	char str[5];
	scanf("%c", str);
	printf("%s\n", str);
	return str;
}



int main(void)
{

	int i;
	
	//i = decimal_func(i);
	//printf("i = %d\n",i); //输出控制符不需要加取地址符"&"

	i = hexadecimal_func(i);
	printf("i = 0x%x\n",i); 
	
	char 
	i = char_func();
	



	//4,输出控制符里有"\n"的情况见:ScanfLineNext.c
	return 0;
}

