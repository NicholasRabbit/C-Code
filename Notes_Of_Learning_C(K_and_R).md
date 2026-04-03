### Chapter 1 A Tutorial Introduction

#### 1.1 Getting Started

1. *At this point, we are not trying to be complete or even precise (save that the examples are meant to be correct) .*

   What does the sentence in the parentheses mean?

   "save that": except for / with the exception

   "are meant to":  (be meant to be something) to be generally considered to be something.

   It means that the examples provided in the book are intended to correct.

#### 1.4 Symbolic Constants

Why do we use symbolic constants or symbolic parameters?

The reason is that when there are numbers, such as 12, 300 and so on, in code, it is hard to understand. Hence, replacing them with meaningful or symbolic constants can make the program more readable. 

In order to distinguish with variables, symbolic constants are written in upper case. 

```c
#define LOWER 0
#define HIGHER 300  
```



#### 1.7 Functions 

```c
int power(int m, int n);  // Prototype of 'power'
int main()
{
    return 0;
}
int power(int base, int n)  // The definition of 'power'
{
    int i, p;
    for (i = 1; i <= n; ++i)
        p = p * base;
    return p;
}
```



(1) The names used by `power(int base, int n)` for its parameters are local to `power(...)`, and are not visible for other functions; therefore, other functions can use the same names without conflict. It is the same with local variables. 

(2) Generally in C,  we use *parameter* for a variable parenthesised in a function, and *argument* for the value in a call of the function. Apparently, Java follows suit. 

(3) `int power(int m, int n);` is a *function prototype*.  The `int` before `power` is the return type of this function; it can be omitted since the return type  of a function is integer by default. 

The prototype of a function can be declared first, the definition of this function can be written later.

(4) Undeclared parameters are treated as `int`.

```c
int foo(i, j); // i, j are integer type by default.
```

#### 1.8 Arguments--Call by Value

1. In C, all function arguments are passed "by value". The called function can't directly alter a variable in the calling function. Parameters in a called function can be treated as local variables. 

   If necessary, it is possible for a called function to modify the variable in a calling one. The parameter must be the address of the variable, namely a pointer to it. As a result, the called function can have access to the variable indirectly through this pointer. 

   It is different with that the parameter is an array, the argument of an array is actually the address of its first element. The called function can update any element of this array by increment the address. 

   In conclusion, although parameters might be pointers or arrays, the arguments are also the value; they the value of them. The called function can't alter the "value" of pointer or arrays in the calling function. 

   ```c
   
   void get_char(char *cp);
   
   int main(int argc, char *argv[])
   {
       char *cp;
       cp = "a";
       get_char(cp);
       printf("cp = %p, *cp = %c\n", cp, *cp);
   
       return 0;
   }
   
   void get_char(char *cp)
   {
       // Neither does it alter the value to which "cp" dereferences in the calling 
       // function, nor does it modify the value of "cp" in the calling function. 
       // Thus, in main(calling function) the "*cp" is still "a". 
       // To modify the string to "A", we need a pointer of a pointer. To be continued...
       cp = "A";  
   }
   ```

   Below is the disassemble code of `get_char(...)`. When we examine the string stored at `-0x8(%rbp)` in `0x4005e7` by `(gdb) x/s ($rbp - 0x8)` in GDB, we find that it is 'A'. 
   
   ```assembly
   void get_char(char *cp)
   {
     4005d3:   55                      push   %rbp
     4005d4:   48 89 e5                mov    %rsp,%rbp
     4005d7:   48 83 ec 20             sub    $0x20,%rsp
     4005db:   48 89 7d e8             mov    %rdi,-0x18(%rbp)
     4005df:   48 c7 45 f8 bd 06 40    movq   $0x4006bd,-0x8(%rbp)
     4005e6:   00
       cp = "A";
     4005e7:   48 8b 45 f8             mov    -0x8(%rbp),%rax
     4005eb:   48 89 c6                mov    %rax,%rsi
     4005ee:   bf bf 06 40 00          mov    $0x4006bf,%edi
     4005f3:   b8 00 00 00 00          mov    $0x0,%eax
     4005f8:   e8 13 fe ff ff          callq  400410 <printf@plt>
    }
   ```
   



#### 1.9 Character Arrays

(1) Note that in `h, e, l, l, o, \n, \0` the mark of end `\0` is not the last character of the array, therefore, the length of the array is 6 with `\n` as the last object.  

#### 1.10 External Variables and Scope

(1)  `extern` and header files: 

When a program is compiled with multiple source files, as an illustration, file1, file2, and file3, and a variable defined in file1 is used in file2 or file3, `extern` are needed in the latter. Whereas, it is cluttered to declare many variables preceded by `extern`, so we can `#include` header files, namely `file1.h`. That's how the header files are used in practice. 

 (2) `tab` doesn't move specific columns but moves enough spaces to the next tab stop. See the note of exercise 1.20. 

### Chapter 2

General notes:

1. `const` prevents variables from being modified. 

#### 2.1 Variable Names

(1) What does "At least the first 31 characters of an internal name are significant" in the book?

It means that a C compiler only treat the first 31 characters of an internal names(e.g. variables, functions which are only used in one source file) as meaningful. In other words, if two variables have the same 31 characters from the beginning, they are the same even though the rest ones are different.  

(2) Explanation of "For external names, the standard guarantees uniqueness only for 6 characters and a single case".

It is possibly an old C convention. "external names" are the names that out of a source file. The compiler only read the first 6 characters of them and abandons all the rest characters. To illustrate, if two external variable or functions have first 6 of identical names and they are the same no matter what the characters are afterwards. 

(3) N.B.

Note that the following `1` is treated as an integer by default, therefore, it can't be shifted by 63 bits. There will an an warning: "count >= 32", which indicates "1" is an integer by default. In order to shift bits in `1` as a long data, we should declare a long variable and then shift. 

```c
// 1 is an ineter by default even though it is assigned to a long
long min_long = 1 << 63;   

// 2 Shift the bits of a long variable instead. 
long min_long = 1;
// min_long is a long integer now, so it can be shifted by 63 bits. 
min_long <<= 63;
```

(4) An excerpt from "6.S081 Intro to C Fa21" of tutorials of lecture 2.

- In C, value do not store any type information. All type information is stored in variables, which let the code to be executed if it doesn't need to check what types they are. It is different with Python, in Python each value is stored in a region of memory, where the type and the value reside. 
- A value only has a specific type because it is stored in a variable of that type. It is only allocated in the memory with enough space.
- Furthermore,   the information of type only exists when a programme is being compiled; it does NOT exist anymore when the programme is being executed.

#### 2.4 Declarations

(1) What is an automatic variable ?

An automatic variable is also called local variable, it is declared in a function or a block and can be only access within. Its default value is garbage value and it life ends till the end of the function.  

```c
int main() 
{
    auto int i;  // "auto" is optional here since all the lcoal variables are automatic.
}
```

#### 2.5 Arithmetic Operators

1. % can not be used with `float` or `double`.

#### 2.7 Type Conversions

1. Attention should be paid is that when `char` is converted to an integer, it could be a negative integer in some machines where 1 is set to default the extended bit.

2. In page 45, Explanation of "In the absence function prototype, `char` and `short` become `int`, and `float` becomes `double`" .  See my code in chapter 2: `argument_conversion.c`.

   In essence, `char c` is char, but passed as `int` and received as `char` in the function `arg2`.

   ```c
   #include <stdio.h>
   
   void arg1(arg)
   {
       char c = arg;
   }
   
   void arg2(char c)
   {
       char c2 = c;
       printf("c2 is %c\n", c2);
   }
   
   /*
    * In the main function, since the caller, namely "main", doesn't "see"
    * the prototype of argument, the parameter will be converted to int automatically.
    * That happens both of the calling of "arg1" and "arg2", even though the type of
    * the argumentis delcared in the function "arg2".
    * See the assembly code, "c" has been extended by "movzbl or movsbl".
    * */
   int main(int argc, char *argv[])
   {
       char c;
       arg1(c);
       arg2(c);
   
       return 0;
   }
   ```

   The assembly of the above code. 

   ```assembly
    	128 0000000000400536 <arg2>:
       129   400536:       55                      push   %rbp
       130   400537:       48 89 e5                mov    %rsp,%rbp
       131   40053a:       48 83 ec 20             sub    $0x20,%rsp
       132   40053e:       89 f8                   mov    %edi,%eax
       133   400540:       88 45 ec                mov    %al,-0x14(%rbp)
       134   400543:       0f b6 45 ec             movzbl -0x14(%rbp),%eax
       135   400547:       88 45 ff                mov    %al,-0x1(%rbp)
       136   40054a:       0f be 45 ff             movsbl -0x1(%rbp),%eax
       137   40054e:       89 c6                   mov    %eax,%esi
       138   400550:       bf 30 06 40 00          mov    $0x400630,%edi
       139   400555:       b8 00 00 00 00          mov    $0x0,%eax
       140   40055a:       e8 b1 fe ff ff          callq  400410 <printf@plt>
       141   40055f:       c9                      leaveq
       142   400560:       c3                      retq
       143
       144 0000000000400561 <main>:
       145   400561:       55                      push   %rbp
       146   400562:       48 89 e5                mov    %rsp,%rbp
       147   400565:       48 83 ec 20             sub    $0x20,%rsp
       148   400569:       89 7d ec                mov    %edi,-0x14(%rbp)
       149   40056c:       48 89 75 e0             mov    %rsi,-0x20(%rbp)
       150   400570:       0f be 45 ff             movsbl -0x1(%rbp),%eax
       151   400574:       89 c7                   mov    %eax,%edi
       152   400576:       b8 00 00 00 00          mov    $0x0,%eax
       153   40057b:       e8 ad ff ff ff          callq  40052d <arg1>
       # Before calling arg2, the bits of the argument is extended. 
       154   400580:       0f be 45 ff             movsbl -0x1(%rbp),%eax
       155   400584:       89 c7                   mov    %eax,%edi
       156   400586:       e8 ab ff ff ff          callq  400536 <arg2>
       157   40058b:       b8 00 00 00 00          mov    $0x0,%eax
       158   400590:       c9                      leaveq
       159   400591:       c3                      retq
       160   400592:       66 2e 0f 1f 84 00 00    nopw   %cs:0x0(%rax,%rax,1)
       161   400599:       00 00 00
       162   40059c:       0f 1f 40 00             nopl   0x0(%rax)
   
   ```

     

#### 2.9 Bitwise Operators

1. What is "right adjusted" in the function of `getbits(x, p, n)` in page 49 ? 

   Suppose we have x(`0b0111,0110`) and we need a segment of bits from the index 1 to 3 from the left end. It is `getbits(x, 4, 3)`m, namely we need three bits from the 4th to the right. That is "right adjusted". Finally, we get `011`. 



#### 2.10 Assignment Operators and Expressions

1. What is the difference between `+=` and `+`? 

   Note that `+=` is an assignment operator and `+` is a binary operator. 

   After disassembling the object file of a C programme with both of these two operators, I find that the instructions for them are the same at machine-level operation. Whereas, it said that an assignment operator may help a compiler to generate a more efficient program. 

#### 2.11 Conditional Expressions

**(1) What is a conditional expression ?** 

As an illustration, `expr1 ? expr2 : expr3` is an conditional expression and it is an alternative way to a conditional statement (`if...else` ). 

**(2) Is a conditional expression faster than a `if...else` statement ?** 

A "conditional expression" is interpreted to "a conditional data transfer" in machine-level code, which outperforms than a conditional statement(`if...else`), which is interpreted to "a "conditional control transfer" in assembly. See chapter 3.6.6 of CASPP 2e and my corresponding notes. 

Since a processor predicts when there is a conditional instruction, if it make a incorrect prediction in a" conditional control transfer ", it invites severe penalty by wasting up to 20 to 40 clocks. 

Let's examine the assembly code of `max.c` to prove that. 

```c
// max.c
// Conditional control transfer.
int max1(int a, int b)
{
	int z;
	if (a > b)
		z = a;
	else 
		z = b;
	return z;
}

// Conditional data transfer.
int max2(int a, int b)
{
	return a > b ? a : b;
}
```

The disassembled code of these functions. 

```assembly
0000000000000000 <max1>:
   0:	55                   	push   %rbp
   1:	48 89 e5             	mov    %rsp,%rbp
   4:	89 7d ec             	mov    %edi,-0x14(%rbp)
   7:	89 75 e8             	mov    %esi,-0x18(%rbp)
   a:	8b 45 ec             	mov    -0x14(%rbp),%eax
   d:	3b 45 e8             	cmp    -0x18(%rbp),%eax
  10:	7e 08                	jle    1a <max1+0x1a>
  12:	8b 45 ec             	mov    -0x14(%rbp),%eax
  15:	89 45 fc             	mov    %eax,-0x4(%rbp)
  18:	eb 06                	jmp    20 <max1+0x20>
  1a:	8b 45 e8             	mov    -0x18(%rbp),%eax
  1d:	89 45 fc             	mov    %eax,-0x4(%rbp)
  20:	8b 45 fc             	mov    -0x4(%rbp),%eax
  23:	5d                   	pop    %rbp
  24:	c3                   	retq   

0000000000000025 <max2>:
  25:	55                   	push   %rbp
  26:	48 89 e5             	mov    %rsp,%rbp
  29:	89 7d fc             	mov    %edi,-0x4(%rbp)
  2c:	89 75 f8             	mov    %esi,-0x8(%rbp)
  2f:	8b 45 fc             	mov    -0x4(%rbp),%eax
  32:	39 45 f8             	cmp    %eax,-0x8(%rbp)
  35:	0f 4d 45 f8          	cmovge -0x8(%rbp),%eax
  39:	5d                   	pop    %rbp
  3a:	c3                   	retq   
```

As can be seen in the assembly code, there are conditional transfer controls in `max2` and conditional data transfer in `max2`. Most of the modern pipeplined processors support conditional data transfer, therefore, `max2` is much faster. 

### Chapter 5

#### General notes of pointer

1. Returning address(pointer) of a local variable is dangerous because the stack of the function will be reset when it is finished which leads to the memory where the pointer points being replaced by new functions. 

#### 5.1 Pointers and Addresses

(1) The declaration of a pointer imitate the way of declaring a common variable. As an illustration,  `int *ip` indicates that `*ip` has the value of integer, however, `ip` itself is a variable which stores the address of this value of integer. 

(2) A pointer is specified as a particular type of variable, namely a pointer is bound with or points to only one type of variable when it is declared. An exception is that `void *` can point to any data type except for itself. To illustrate, `int *ip` declares a pointer which can only point to an integer. 

(3) `*` and `&` have higher precedence than arithmetic operators. Hence, `y = *ip + 1` obtains `*ip`  first and then add 1 and assigns the sum to y.  Note that `++*ip` does the same, but `(*ip)++`  should have parentheses to have the same result since unary operators like `*` and `++` associate right to left, which means in `*ip++` the compiler groups them from right, therefore, `ip++` is treated as a whole by `*`; that is as same as `*(ip++)`, which is not we expect. 

(4) A pointer must be initialised before being assigned any specific data. Don't ignore the warning when compiling with `gcc -Wall`, it reminds me of initialising the `dp` before using it. Whereas, I didn't notice it. 

```c
double *dp;  
double d = 3.1415926;  
// A bug.
*dp = d;   // dp hasn't been initialised and it contains a gargage value. 
```

#### 5.3 Pointers and Arrays

1) Why is there a segment fault in the following code ? 

``` c
char *s = "x";
int cookie = 0x59b997fa;
sprintf(s, "%.8x", cookie);    
```

"x" is a string literal, and in C, string literals are stored in read-only memory. 

2) A side effect of pointer arithmetic. (from "Intro-to-C-Fa21, Lecture 2" of 6S081). 

```c
 int values[5] = {10, 20, 30, 40, 50};
// The two print out the same result: 50 since "x + y = y + x".
 printf("%d\n", 4[values]);
 printf("%d\n", values[4]);
```

