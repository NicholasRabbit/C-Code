# include<stdio.h>

/*
 * ASCII的取值范围是0~127, 没有负数。
 * */

int main(){
	
	//本例演示为什么使用输出控制符
	char ch = 'A';
	printf("%c\n",ch);	//输出：A,因为“%c”就是设定输出为char类型
	printf("%d\n",ch);	//输出: 65,即A的ASCII码，因为"%d"设定就是输出数字

	char ch2 = 'a';
	printf("%c\n",ch2);	//输出：a
	printf("%c\n", ch2 + 1);	//输出：b,字符也可以参与运算。
	printf("%d\n", ch2);  // As a matter of fact, the value of char is also numbers.

	/*总结：
	 *以上说明在底层计算机都是用数字，即二进制来表示任何数据的包括以上的字符，还有字符串
	 *图片，视频等也都是以二进制形式表示的，只是展示的时候转换为了图片视频而已。 
	 *char本质上就是整数，只不过比int类型的范围小而已。
	 */

}
