```c
int main () {
    int i = 0xcffffff3; // 
    printf("%x\n", 0xcffffff3>>2);  //0xCFFFFFF3= 0b11001111111111111111111111110011
    printf("%x\n", i>>2);
}
```



It all comes down to `0xcffffff3`. That is an hexadecimal integer constant. The type of the constant depends on its magnitude. Let's refer to [C11 § 6.4.4.1 ¶ 5](http://port70.net/~nsz/c/c11/n1570.html#6.4.4.1p5):

> The type of an integer constant is the first of the corresponding list in which its value can be represented.
>
> **Octal or Hexadecimal Constant** - int, unsigned int, long int, unsigned long int, long long int, unsigned long long int

So assuming 32 bit integer representation on your system. The type of `0xcffffff3` is unsigned int.

Now, when you do `int i = 0xcffffff3;` the unsigned constant is converted to a signed integer. This conversion yields a negative value.

Finally, when right shifting, it has the semantics defined by [C11 §6.5.7 ¶5](http://port70.net/~nsz/c/c11/n1570.html#6.5.7p5):

> The result of E1 >> E2 is E1 right-shifted E2 bit positions. If E1 has an unsigned type or if E1 has a signed type and a nonnegative value, the value of the result is the integral part of the quotient of E1 / 2E2 . If E1 has a signed type and a negative value, the resulting value is implementation-defined.

Shifting the unsigned constant yields `0xcffffff3/4` and shifting `i` yields an implementation defined value (a negative integer in this case).

