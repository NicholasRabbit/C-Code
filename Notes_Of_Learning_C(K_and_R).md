### Chapter 1 A Tutorial Introduction

#### 1.1 Getting Started

1. *At this point, we are not trying to be complete or even precise (save that the examples are meant to be correct) .*

   What does the sentence in the parentheses mean?

   "save that": except for / with the exception

   "are meant to":  (be meant to be something) to be generally considered to be something.

   It means that the examples provided in the book are intended to correct.

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
   
   

