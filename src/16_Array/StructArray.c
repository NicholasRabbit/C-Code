# include<stdio.h>

/*
 * Array of struct in C.
 *
 * */

//A global variable should be initialised at the moment when it is declared.
struct student{
	
	char name [20]; // an array could be also in a struct.
	int age;
	double score,weight;

} arrayStruct [5] = { {"Tom",15,56.60}, };  //The rest elements will be set default value by complier.


//array could not be assigned as a return value.
int getArr(double x,double y){

	printf("%s\n",arrayStruct[0].name);

	struct student stu = arrayStruct[1];
	//stu.name[20]  = "Jerry";  //error: An variable of array which have been intialised could not be assigned with "abc" or {'a','b','c'}
								//Reason is: a string value will be transfered to a pointer automatically by compiler. Refer to "String.c".
	stu.name[0] = 'x';  //Correct way of assignment.

	stu.age = 20;
	stu.score = 33.5;
	stu.weight = 90.0;
	printf("%s,%d,%f,%f\n",stu.name,stu.age,stu.score,stu.weight);

	return  0;
	
}

int main(void){

	getArr(1.2,3.5);

	return 0;
}

