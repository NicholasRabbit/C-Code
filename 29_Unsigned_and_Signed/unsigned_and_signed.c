# include<stdio.h>


int main(void)
{
	/*
	 * 1. An unsigned number is always bigger than 0.
	 * The for loop below is endless no matter how many times it minus one.
	 * */
	/*
	unsigned int i;
	for(i = 10; i > 0; i--){
		printf("%u\n", i);
	} */
	
	// 2. We can add "U/u" as suffix to declare unsigned constants.
	unsigned num = 128U;
	printf("unsigned: %u\n", num);
	

	/*
	 * 3. Whean an operation is performed where one operand is signed and 
	 *    the other is unsigned, C implicitly cast the signed argument to
	 *    unsigned.
	 * */
	// -1 is 0xffffffff = 4294967295U. So the result is 0, namely false.
	int result = -1 < 0U;  
	printf("-1 < 0U ==> %d\n", result);
	

	/*
	 * 4. Cast a signed number to unsigned or vice versa.
	 * */
	int s = -1;
	unsigned int u = (unsigned)s;
	printf("unsigned value of -1(int)==> %u\n", u);

	return 0;

}
