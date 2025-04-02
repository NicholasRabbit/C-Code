# include<stdio.h>

/*
 * A structed is embedded in another struct.
 * */


//a simple struct
struct complexStruct {
	double x, y;
};

//a segment struct which consists of two simple structures.
struct segmentStruct {
	struct complexStruct z1;
	struct complexStruct z2;
};


int main(void){

	//ways of initialised 
	//1
	struct segmentStruct t1 = { {1.0,2.0},{ 3.0,4.0} };
	//2
	struct segmentStruct t2 = {2.5,3.5,4.5,5.5};
	//3, it is not suggested because it can't be read friendly.
	struct segmentStruct t3 = {{3.3,4.3}, 6.1,9.5};
	//4, new feature of C99. Caution: A "." must be added before every variable.
	struct segmentStruct t4 = {.z1.x = 15.0,.z2.y = 36.0};  //values of unassigned fileds are 0 by default.


	//assign a value 
	t1.z1.x = 5.6;
	t1.z1.y = 1.5;
	t1.z2.x = 2.0;
	t1.z2.y = 7.9;
	printf("%f,%f,%f,%f\n",t1.z1.x,t1.z1.y,t1.z2.x,t1.z2.y);

	return 0;

}
