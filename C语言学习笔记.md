#### 1，Widows下配置gcc环境

配置mingw即可，详情参照mingw配置教程

#### 2，C语言程序开头代码的含义

```txt
程序第一行的#号（Pound Sign，Number Sign或Hash Sign）和include表示包含一个头文件（Header File），后面尖括号（Angel Bracket）中就是文件名（这些头文件通常位于/usr/include目录下）。头文件中声明了我们程序中使用的库函数，根据先声明后使用的原则，要使用printf函数必须包含stdio.h，要使用数学函数必须包含math.h，如果什么库函数都不使用就不必包含任何头文件，例如写一个程序int main(void){int a;a=2;return 0;}，不需要包含头文件就可以编译通过，当然这个程序什么也做不了。

注意：使用math.h中声明的库函数还有一点特殊之处，gcc命令行必须加-lm选项，
因为数学函数位于libm.so库文件中（这些库文件通常位于/lib目录下），-lm选项告诉编译器，我们程序中用到的数学函数要到这个库文件里找。本书用到的大部分库函数（例如printf）位于libc.so库文件中，使用libc.so中的库函数在编译时不需要加-lc选项，当然加了也不算错，因为这个选项是gcc的默认选项。关于头文件和库函数目前理解这么多就可以了
```

#### 3，使用math.h库时注意

后面要加 -lm，否则编译不通过。

```shell
 gcc -Wall RoundNumber.c -o RoundNumber.out -lm
```

