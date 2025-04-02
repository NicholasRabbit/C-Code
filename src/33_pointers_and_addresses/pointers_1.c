# include<stdio.h>

/*
 * Although pointers could be pointed to different types such as 
 * int, char, short, float, double, and long, the length of any
 * pointers is 32 bytes in x86 or IA32 all the time.
 * A pointer in C is used for storing the value of address 
 * of a variable or an array.
 *
 * Symbols used in pointers:
 * &: It gives the address of an object(variables, arrays and so forth).
 *    '&' operator can only apply to objects in memory: variables and array
 *    elements. It can not be applied to expressions, constants, or register
 *    variables.
 * *: When '*' applied to a pointer, it accesses the object the pointer
 *    points to.
 *    N.B. "*ip" indicates the value where a pointer deferences. "ip" is the 
 *    pointer.
 * 
 * */
int main (void) 
{

	int x = 1, y = 2, z[10];

	// Declaring a pointer to point integer data type.
	int *ip; 
	// Now ip point to x.
	ip = &x;
	// 'y' is now 1.
	y = *ip;
	printf("y is %d\n", y);
	// 'x' is now 0 because '*ip' is assigned with '0'.
	*ip = 0;
	printf("*ip is %d\n", *ip);
	printf("x is %d\n", x);

	// 'ip' is now pointed to 'z[0]'
	ip = &z[0];
	printf("after pointing to z[0], *ip is %d\n", *ip);

	

	return 0;
}
