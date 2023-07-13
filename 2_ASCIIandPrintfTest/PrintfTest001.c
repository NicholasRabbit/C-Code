# include<stdio.h>
int main(void){
	int i = 10;
	/*1,%d表示把i以10进制的形式输出;
	 *2,%x,%X表示以16进制输出，这俩意思一样,一般都用大写，好区分;
	 * */
	printf("%d\n",i);
	printf("%X\n",i);	//10用16进制表示就是a,即9后面就是a。

	int j = 15;
	printf("%X\n",j);
}
