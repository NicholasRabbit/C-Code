# include<stdio.h>

/*
 * union
 * The syntax is based on structures.
 * */
int main(void){
	
	union u_tag {
		char c;
		short s;
		int i;

	};

	//Declaration
	union u_tag demo_union;
	
	demo_union.c = 'A';

	printf("union = %c\n", demo_union.c);


	return 0;
}


