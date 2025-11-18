### Chapter 1 A Tutorial Introduction

#### 1.7 Functions 

```c
int power(int m, int n);
int main()
{
    return 0;
}
int power(int base, int n)
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