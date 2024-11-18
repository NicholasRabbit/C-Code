# include<stdio.h>

//Calculate if a provided year is leap year
int isLeapYear(int year){

	if(year < 0)
		return 0;

	if( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0 )
		return 1;
	else 
		return 0;

}


//call the function
int main(void){

	int leap;

	printf("please input a year:");

	scanf("%d",&leap);

	int isLeap = isLeapYear(leap);

	printf("isLeap = %d \n",isLeap);

	return 0;


}
