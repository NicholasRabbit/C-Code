#include <stdio.h>

void pointers_and_addresses()
{

	int x = 1, y = 2, z[10];

	// 1. "*ip" is represented by 0x__(%rbp) in the assembly.
	int *ip;
	ip = &x;  
	y = *ip;
	*ip = 0;
	ip = &z[0];


	// 2. double
	double *dp, atof(char *);
	double d = 3.1415926;
	
	//*dp = d; // This line of code is wrong because 'dp' hasn't been initialised yet.
	dp = &d;
	printf("*dp is %lf\n", *dp);
	
	// 3. Incrementing an object and a pointer.
	y = *ip + 1;
	printf("y is %d\n", y);
	
	*ip += 1;
	printf("*ip += 1 is %d\n", *ip);

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
