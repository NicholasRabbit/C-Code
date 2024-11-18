#include <stdio.h>

/*
 * Line Feed demo.
 * 换行符范例，跟java中相同。
 * 转义符范例。
 * */
int main(){

	printf("Hello, \n");
	printf("World! \n");

	//'%'转义,使用两个%%，不是使用'\'
	printf("%% \n");
	return 0;

}
