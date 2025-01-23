## CHAPTER 1: A Tutorial Introduction

### 1.1 Getting Started

1.  *At this point, we are not trying to be complete or even precise (save that the examples are meant to be correct) .*

   What does the sentence in the parentheses mean?

   "save that": except for / with the exception

   "are meant to":  (be meant to be something) to be generally considered to be something.

   It means that the examples provided in the book are intended to correct.

### 1.7 Function

1. Undeclared parameters are treated as `int`.

   ```c
   int foo(i, j); // i, j are integer type by default.
   ```

2. The prototype of a function can be declared first, the definition of this function can be written later.

   ```c
   int power(int m, int n);  // Prototype of 'power'
   
   main()
   {
       int i;
   
       for (i = 0; i < 10; ++i)
           printf("%d %d %d\n", i, power(2,i), power(-3,i));
       return 0;
   }
   
   int power(int base, int n) // The definition of 'power'
   {
       int i, p;
       p = 1;
       for (i = 1; i <= n; ++i)
           p = p * base;
       return p;
   }
   ```

   