#### 一,  第 16 章 运算符详解 

1. 位运算 

```txt
习题
1、统计一个无符号整数的二进制表示中1的个数，函数原型是int countbit(unsigned int x);。
答案见23_Bitwise内coursewok

2、用位操作实现无符号整数的乘法运算，函数原型是unsigned int multiply(unsigned int x, unsigned int y);。例如：(11011)×(10010)=((11011)<<1)+((11011)<<4)。
例题分析：
后面的10010中1对应的指数幂是4，2
(11011)×(10010) = 11011 x (10000 + 10)
 			    = 11011 x (16 + 2)
				= (11011)<<4) + (11011)<<1
3、对一个32位无符号整数做循环右移，函数原型是unsigned int rotate_right(unsigned int x);。所谓循环右移就是把低位移出去的部分再补到高位上去，例如rotate_right(0xdeadbeef, 16)的值应该是0xefdeadbe。
```

