# include<stdio.h>

/*
 * 什么是mask掩码？用来做什么？
 * 如果相对二进制整数中的某些位置进行操作，就需要掩码来表示这些整数
 * 的位置。类似于计算机网络中的子网掩码，规定子网中ip的个数一样。
 *
 *
 * Mask掩码计算范例
 * 掩码针对的是二进制，但是本例全部用16进制表示，省空间且和二进制转换方便。一个16进制位表示4个二进制位。
 *
 * */
int main(void){
	
	
	//一，取出一个32位数的二进制数的8~15位数(下标从0开始,因为计算时也是从2^0开始算)
	//注意使用unsigned关键字修饰，防止编译器默认的正负数干扰。
	unsigned int num, result, mask = 0x0000ff00; //把掩码的8~15位全置为1，其它位置是0
	
	num = 0x12345678;	
	/*
	 * 方法一：
	 * 步骤分析：
	 * 1，首先把原数和掩码按位与，可得到：0x00005600
	 * 2, 然后向右移动8个位置，移动到了个位十位，就得到了最终结果。
	 * */
	result = (num & mask) >> 8;
	printf("result(hexadecimal)==>%x\n", result);

	/*
	 * 方法二；
	 * 步骤分析：
	 * 1，~0U(unsigned)取反得到0xffffffff, 左移8位得到0xffffff00;
	 * 2, num右移8位0x00123456,两者按位与后得到结果。
	 * */
	int result02 = 0;
	result02 = (num >> 8) & ~(~0U << 8);
	printf("%x\n", num >> 8);
	printf("%x\n", ~0U);
	printf("result02(hexadecimal)==>%x\n", result02);
	

	//二，把该数的8~15位清零。
	//因为补码的8~15全是1，取反后变为0，在和原数8~15位置按位与即可。
	int set_zero = num & ~mask;
	printf("set_zero(hexadecimal)==> %x\n", set_zero);


	//三，把8~15位全置为1
	int set_one = num | mask;
	printf("set_one(hexadecimal)==> %x\n", set_one);

	return 0;
}
