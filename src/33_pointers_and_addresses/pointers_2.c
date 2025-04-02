# include<stdio.h>


int main (void) 
{

	/*
	 * 1.Every pointer point to a specific data type. 
	 * Whereas, there is an exception: 
	 * A pointer to 'void' is used to hold any type of pointer 
	 * but can not be used to dereference itself.
	 * */
	void *p;

	/*
	 * 2. Parameters can be pointers. For example, in the function "atof(char *)" the 
	 * argument is a pointer to char.
	 * */
	double *dp, atof(char *);

	/*
	 * 3. If 'ip' is a pointer which points to 'x' it can occur/appear any context 
	 * where x could.
	 * */
	int x = 10;
	int y = 3;
	int *ip;
	ip = &x;
	
	*ip = *ip + 2; // x = x + 2
	
	y = *ip + 5;
	
	*ip += 1;

	++(*ip);

	/*
	 * 4. N.B. "*ip" should be put in parentheses because unary operators like 
	 * "++, *" associate right to left. If not, "ip" will increment 1.
	 * */ 
	(*ip)++; 

	printf("*ip is %d\n", *ip);
	printf("y is %d\n", y);

	/*
	 * 5. Since pointers are variables, they can be used without deferencing. 
	 * For example, we can directly use the pointer "ip" to assign its value
	 * to another pointer.
	 * */
	int *iq;
	iq = ip;
	printf("*iq is %d\n", *iq);




	return 0;
}
