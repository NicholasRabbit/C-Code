# include<stdio.h>

/*
 * Exculsive OR operation. 
 * */
int main(void){
	
	// 1, Any binary number that do the operation of XOR(exclusive OR) with itself could get 0.
	unsigned int i = 0x3ff;
	i = i ^ i;
	printf("i^i = %x\n", i);

	// 2, The XOR of 0 and any number is the number itself; the XOR of 1 and any number it the opposite of the number.
	// 利用此特性结合掩码可以实现某个位的反转。
	unsigned int j, k, mask;
	j = 0x12345678;
	mask = 1U << 6;  //把1左移6位
	k = j ^ mask;    //filp the sixth bit.
	// 0x12345678的5到8：0111, 反转后: 0011。1U原来在第一位，右移动6位就到了7位。
	printf("k: %x\n", k);  //0x12345638


	/*
	 * 3, If the result of given bits a1^a2^a3...a4 is 1, the total numbers of '1' at all bits is odd.
	 *    Otherwise, it is even.
	 * */
	unsigned int m, n, o;
	m = 1;
	n = 0;
	o = 1;
	int count = m ^ n ^ o;
	printf("odd or even? ==> %u\n", count);  

	/*
	 * 4, To exchange the value of two numbers with using any other varialbe.
	 * e.g. 
	 * x ^ x ^ y == y
	 * x ^ x = 0
	 * 0 ^ y = y
	 * */
	unsigned int a,b;
	a = 0x234;
	b = 0x753;
	a = a ^ b;  // Q
	b = b ^ a;  // b = b ^ b ^ a = a;
	/*
	 * On the right side of "=" because b is a now, then a = a ^ (Q) = a ^ (a ^ b).
	 * So "a" equals "a ^ a ^ b" which is "b".
	 * */ 
	a = a ^ b;  
	printf("a = %x\n", a);
	printf("b = %x\n", b);

	
	

	return 0;
}
