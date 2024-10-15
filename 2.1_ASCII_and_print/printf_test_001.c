# include<stdio.h>


/*
 * Format of printing values.
 * */
int main(void){
	

	/*
	 * 0, How to print '%' itself?
	 *	  Using "%%".
	 * */
	printf("%%\n");


	/*
	 * 1,%d: 'd' is short for "decimal". It means that to print the value 
	 *       in a decimal integer.
	 *   %u: to print unsigend decimal integer.
	 *   
	 *   %6d: print a decimal integer with at least 6 characters.
	 * */
	int i;
	i = -1;
	printf("%%d: %d\n",i);   
	printf("u: %u\n", i);
	printf("6d: %6d\n", i);

	/*
	 * 2,%x or %X: To print the hexadecimal value of a argument.
	 *   %.2x : That indicates that an integer should be printed in hexadecimal 
	 *          with at least 2 digits. 
	 * */
	int j = 15;
	printf("j's hexadecimal value is %X\n", j);

	/*
	 * 3,%f: print as floating point.
	 *   %lf: print as double floating point.
	 *
	 *	 %3.0f: It means that a floating number is to be printed at least 
	 *	        three characters wide without no decimal point or fractinal digits.
	 *	        For example: 3.22 -> 3
	 *	 %6.2f: It means that a floating number is to be printed as least
	 *	        six characters wide with 1 digit after the decimal point.
	 *
	 *   N.B. The function "printf(...)" casts 'float' to 'double' by default,
	 *   but "scanf(...)" doesn't. See "DoubleFloatAndPrintfScanf.c".
	 * */
	float f0, f1, f2;
	f0 = 12.9;
	printf("f0 = %f\n", f0); 

	f1 = 20.0 / 6.0;
	f2 = 3.020304; 
	printf("f1 = %3.0f\n", f1);
	printf("f1 = %6.2f\n", f2);

	double d1 = 82.35;
	printf("d1 = %lf\n", d1);

	/*
	 * 4,%ld: print as signed long integer.
	 *   %lu: to print unsigned long integer.
	 * */
	unsigned long m = 0xffffffffffffffff; // (2 to the power of 32) - 1
	printf("ld = %ld\n", m);   
	printf("lu = %lu\n", m);


	/*
	 * 5, %p: print as hexadecimal representation of a pointer.
	 * */
	int num = 10;
	printf("p: %p\n", &num);


	// 6, %c: print as characters. 
	char c = 98;
	printf("c: %c\n", c);

	return 0;
}

/*
 * N.B. The function "printf(..)" has variable-length arguments.
 * See: man 3 printf. The "3" represents "Section 3" here because
 * there are other functions with the same name in Linux.
 * */
