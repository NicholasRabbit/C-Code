# include<stdio.h>

/*
 * Use struct as arguments of a function.
 * */

//Attention: a struct can be used as the arguments of a function only if it is a global variable.
struct my_struct{
	double x,y;
};

//add two structs
struct my_struct addComplex(struct my_struct z1, struct my_struct z2){

	z1.x = z1.x + z2.x;
	z1.y = z1.y + z2.y;

	return z1;

}

int main(void){

	struct my_struct z1 = {1.5,3.4};
	struct my_struct z2 = {7.6,0.3};

	struct my_struct result = addComplex(z1,z2);

	printf("result(%f,%f)\n",result.x,result.y);

	return 0;
}
