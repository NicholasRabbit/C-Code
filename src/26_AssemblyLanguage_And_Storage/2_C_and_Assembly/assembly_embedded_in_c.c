# include<stdio.h>


/*
 * A C programme is embedded with assembly.
 *
 * */
int main(void){
	

	/*
	 * 1, A simple assembly programme in C.
	 * 2, Caution: there are two '_' on each side of 'asm'.
	 * */
	__asm__("movl $1, %eax\n\t"
		  "movl $5, %ebx\n\t"
		  "int $0x80");   // "int" is short for interrupt not for integer. 


	/*
	 * 2, The second one.
	 * To assign the value of 'a' to 'b'.
	 * */
	int a = 10, b;
	__asm__(//Write assembly language here.
			"movl %1, %%eax\n\t"
			"movl %%eax, %0" 

			//The following codes are optional.
			//Restriction should be written below and seperated from assembly by colon.
			:"=r"(b)   //output. b is in %0.  %0 and %1 are also registers whose name are decided by compiler and 0,1 are indices(indexes).
			:"r"(a)	   //intput. a is in %1.
			:"%eax"    // clobbered registers. 
			);



	int c = 12;
	printf("c = %d\n", c);  //This function is not called. Why?

	return 0;
}
