#include <stdio.h>

void pointers_and_addresses()
{


	/*
	 * 1. Let's start with ampersand: &. It is a unary operator in C to get the addres of an object.
	 * For int x, &x gives the address of x. 
	 *
	 * An inqusitive mind may ask, is it possible to declare a pointer like what we do for an integer?
	 * The answer is Yes. Asterisk, *, is the indirect or dereferencing operator in C. It serves the 
	 * declaration of a pointer.
	 * To illustrate, "int *ip" declares a pointer "ip", but "*ip" is an integer. Do note that it is "ip" that is the pointer, 
	 * not the "*ip". The latter access the object that the pointer points to. 
	 * Once we get the value, which is the address of a variable, we man manipulate it to write conscise code. I hope so.
	 *
	 * C and Assembly (IA32)
	 * If "ip" is a pointer, "*ip" is represented by 0x__(%ebx) in the assembly. 
	 * */ 
	int x = 1, y = 2, z[10];
	printf("&x is %p\n", &x);

	// Let's delcare a pointer and asign it with the addres of x.
	int *ip;
	ip = &x;  
	printf("ip is 0x%x\n\n", ip); // Persumable, ip has the same content with &x.

	y = *ip;
	*ip = 0;
	ip = &z[0];


	// 2. double
	double *dp, atof(char *);
	double d = 3.1415926;
	
	//*dp = d; // It is buggy, because 'dp' hasn't been initialised yet, namely it points to somewhere in the memory.
	dp = &d;
	printf("*dp is %lf\n", *dp);
	
	// 3. Incrementing an object and a pointer.
	y = *ip + 1;
	printf("y is %x\n", y);
	
	*ip += 1;
	printf("*ip += 1 is %x\n", *ip);

	++*ip;
	printf("++*ip is %d\n", *ip);

	printf("Before: ip is %p\n", ip);
	// The "*ip++" increments "ip" first, namely the address is increased by 4. 
	*ip++; 
	printf("After: ip is %p\n", ip);
	printf("*ip++ is %d\n", *ip);

	*ip = 3;
	(*ip)++;
	printf("ip = %p, *(ip)++ is %d\n", ip, *ip);

	// 4. Assigning a pointer to another one.
	// Since pointers are variables, they can be used directly without deferencing. 
	int *iq;
	iq = ip;
	printf("iq = %p, *iq is %d\n", iq, *iq);




}


int main(int argc, char *argv[])
{
	
	pointers_and_addresses();

	return 0;

}
