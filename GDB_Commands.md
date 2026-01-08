## GDB 

### 1, Some tutorials

 Prof. Norm Matloff's  [GDB tutorial](http://heather.cs.ucdavis.edu/~matloff/UnixAndC/CLanguage/Debug.html) .

[CSAPP Student Guide on GDB](http://csapp.cs.cmu.edu/public/students.html)



### 2, gdb debugging

#### 1, Add `-g` to `gcc` 

```shell
gcc -g GDB_Test.c -o test.out
```

Note: the option `-g` is to bind the source code, but doesn't embedded the source code to the compiled file. Thus, the source code should not be removed when it is bound. 

#### 2,  gdb commands

##### 1) Debug Begins

```shell
gdb test.out
```

The interface of GDB will be shown up after entering this command. 

##### 2) help and repeat

```shell
$ gdb test.out
GNU gdb 6.8-debian
....
(gdb)   # 这里可以输入相关命令
(gdb) help # 查看帮助文件
(gdb) help files  # 查看files命令帮助
```

**repeat the last command **

```shell
（gdb） \<Enter\>  # repeat the last command
```

##### 3) list specified function or line

3.1) List lines

```shell
# List 10 lines of source code. If the second option is ommitted, it is 10 by default.
(gdb) list 10 / list 
# Keep on listing. 
(gdb) list  
# Or type "Enter"
(gdb) <Enter> 
# We can show 10 lines of code around a specific line after the above comands.
(gdb)list 15 # To show code from line 10 to 19.
```

如果修改源码的名字或者位置，再执行list命令就会报：No such file or directory 错误。

3.2) List functions

```shell
(gdb)list do_some  # list 10 lines around a function named "do_some"

# List the add method in stack.c when mulitple sources are compiled simultaneously.
# Or list 10 lines of code around the twelfth line in stack.c
# See c-code/src/31_Linked/1_linked_basic
(gdb)list stack.c:add or stack.c:12
```

3.3) To know more about `list` 

```shell
(gdb)help list
```

##### 3a) `info`

```shell
(gdb)info / i  locals  # Examine all the local variables.
# Print current status of a program
(gdb)info progam
(gdb)info functions  # Print all the functions in a programme.
(gdb)info stack		 # Print backtrace of the stack.
(gdb)info frame		 # Print informaion of the current stack frame.
(gdb)info registers  # Print registers and their contents.
(gdb)info breakpoints # Print status of breakpoints which are set by users. 
```



##### 4) start debugging

```shell
> gdb test.out 
(gdb) start 
# or
(gdb)start < psol.txt  # If we want to redirect input to another file. 
```

**4.1 `run` restart debugging**

```shell
(gdb)run # Start it from the beginning when you miss something during debugging. 
(gdb)run < psol.txt  # Redirect input to psol.txt.
```

##### 5) quit debugging

```c
(gdb) quit
```

##### 6) `next` and `step` 

```shell
(gdb) next / n / Enter # execute next line
# When a function is going to be executed, we can step into it. 
(gdb) step / s # step into a function
```

The difference  between `next` and `step` is:

If the next line is a function, entering `next` will pause at the line following this function, while entering `step` will jump into this function. 

When you use `s/step` at a function, the `gdb` will tell you the arguments of it, which is quite convenient 

######     6.1 return from the current function

```shell
(gdb) finish  # Return from the current function. 
```

##### 6) `backtrace` /`bt`  and `where`

```shell
# Print the current address and stack backtrace.
(gdb) backtrace / bt  
#0  add_range (begin=1, end=10) at GDB_Test.c:12
#1  0x000000000040056d in main () at GDB_Test.c:23
-- add_range(..) is called by main(). The arguments are "begin=1, end=10"
# Print the current address and stack backtrace, too.
(gdb)where
```



##### 7) Modifying variables `set` and `print`

```shell
# Alternate the value of `sum` to move on. 
# Don't forget "var" which is a key word, but not a name of a variable.
(gdb) set var sum=0  
```

也可以使用print / p 来修改变量的值，print还可以调用函数。

```shell
(gdb) print / p result[2] = 25  # 随意修改当前栈帧的变量
# 修改后会把值存储在一个编号序号的临时变量里如 $5 25
# 也可以调用函数，实际这里可以随意写个已有的函数如printf(..)
(gdb) print / p printf("%d\n",result[2])
$ 6 4  # 这里接受的是printf(..)函数的返回值。printf(..)函数返回值就是其打印的字符数。
```

##### 8)  display

进入函数后才能使用此命令，否则找不到该局部变量。

```shell
(gdb) info display # 查看已设置的显示点
(gdb) display sum  # 每次程序走一步就显示当前sum的值。可展示多个，执行多次命令即可。
(gdb) display sum2 # ...display the decimal value by default.

(gdb) display # 显示所有设置好的变量值

(gdb) disable diaplay 2 # 禁用显示点2
(gdb) enable display 2  # 启用显示点2

# display the hexadecimal value
(gdb) display/x sum
# display the binary value
(gdb) display/t sum

# undispaly
(gdb) undisplay  1 # Delete a specific auto-display variable. 
(gdb)undisplay  # Delete all auto-display expression.
```

##### 9) breakpoints

- `break, info, disable, enable, delete`

  First of all, show the source code by `(gdb) list 10` and decide where to set a break point.

```shell
(gdb) break / b 15  # Set a break point in the fifteenth line.
(gdb) break do_some # Pause at the first line of a function named "do_some"
(gdb) clear do_some # Clear any breakpoints at the entry of a function named "do_some". 

(gdb) info / i breakpoints  # Show the infomation of breakpoints

(gdb) disable breakpoints 1 # disable a break point
(gdb) enable breakpoints 3 # enable one

(gdb) delete breakpoints 5 # delete a specific break point
(gdb) delete breakpoints  # delete all breakpoints
```

- Set a break point at an address in memory

```shell
(gdb)break *0xffff007  # Note that there is a asterisk before the address. 
```

- `continue` executing until to the first break point.

```shell
(gdb) continue / c  # continue		
```

- `until`

  ```shell
  (gdb)until 3 # Continue running until break point with number 3. 
  ```

  

- invoked by a specific break point/conditional break

```shell
# When sum != 0 it will break here. Other operators like ==,<，> are valid.
(gdb) break 15 if sum != 0  # Don't forget "if" before the boolean expression.
```



(1) Note that a break point in `for` statement is invalid. As an illustration, if we set `b 13 if i > 4`, the break point will never be invoked.  A break point should be set in line 14. I have verified that. 

```c
13  for (i = begin; i <= end; i++)  // A breakpoint set `b 13 if i > 4` here is invalid.
14      sum = sum + i;   // A breakpoint with condition should be here. 
```

(2) When the source has been modified and recompiled, the breakpoints will be updated automatically when we execute the file again. Attention should be paid is that the table of break points invoked by `info breakpoints` has not been updated, but the program will pause in a different line according with the original code at which a break point was set. 

```shell
Breakpoint 1, sum_of_numbers () at break_points_and_others.c:21  # the lastest line.
21                      sum = 0;
(gdb) info b
Num     Type           Disp Enb Address            What
1       breakpoint     keep y   0x00000000004005d8 in sum_of_numbers at break_points_and_others.c:19   # the original number of line
        breakpoint already hit 2 times
```



##### **10) `watch`**

Set memory watch points to pause when specific memory is changed.

```shell
# gdb pauses when "input[8]" is altenated. 
(gdb)watch input[8]  
# Examine the infomation of watchpoints.					
(gdb)info watchpoints 
# We can monitor registers with "watch"
(gdb)watch $edx

# Delete watchpoints
# Watchpoints and breakpoints are in the same table, therefore, 
# they have distinct numbers. 
(gdb)delete 7 
# or 
(gdb)delete watchpoints 7
```

##### 11) `print` 

**(1) printing a value in various format.**

```shell
 # print the decimal value of "sum" by default
(gdb) print sum 
(gdb) print input  # input is a string of "abc"
$1 = 0x603780 <input_strings> "abc" # 0x0x603780 is its address in memory.

# print the hexadecimal representation of a variable.
(gdb) print/x var1  # p/x
# print the binary numbers of a variable
(gdb) print/t var1  # p/t
# print the decimal representation of 0xabc
(gdb)print 0xabc
# print the hexadecimal representation of 255
(gdb)print /x 255
# print characters
(gdb)print /c foo
```

**(2) Printing the value of registers.** Note that the symbol preceding a register's name is $ not % when printing the value of it in `gdb`. 

For IA 32, the program counter is `%eip` while for x86-64, program counter is `%rip`.

```shell
(gdb)print /x $eip  # print program counter in hexadecimal format
(gdb)print /d $eip  # print program counter in decimal format
(gdb)print /t $eip  # print program counter in binary format
# print other registers
(gdb)print /x $ebx  # print contents of %ebx in hexadecimal
(gdb)print /x ($esp + 8) # print contents of `8(%esp)`.
```

**(3) Printing in other formats**

```shell
# 1. print the value in integer at address 0xffffcca8.
(gdb)print *(int *) 0xffffcca8  # in decimal format
(gdb)print /x *(int *) 0xffffcca8  # in hexadecimal format
# 2. print the value in integer at 8(%esp).
(gdb)print *(int *) ($esp + 8)  
# 3. Examine a string stored at 0xbfff890(address).
(gdb)print (char *) 0xbfff890   
```

How can we print the value of  string in memory if we know its pointer(address) in a stack? As an illustration, in `0x8(%ebp)`  is stored the value of a char pointer. How can we know what the string constant?  

See `c_code/src/33_pointers_and_addresses/char_pointers.c` (Compile it to IA32, `gcc -m32 -g ...`)

```assembly
# get_cp
push   %ebp
mov    %esp,%ebp
mov    0x8(%ebp),%eax
pop    %ebp
```

First of all, print the content in `0x8(5ebp)`, which is the value of a char pointer.

```shell
(gdb)print /x ($ebp + 8)
$1 = 0xffffd2c4  # It the address of memory where the pointer is stored.
(gdb)print /x *(int *) 0xffffd2c4 # Print the value of a char pointer in hex format.
$3 = 0x80484a4
(gdb)print (char *)  # Examine a string stored at 0x80484a4.
# There is an implicit "\0"(null character) after "abc" so a compiler know where the 
# the string is terminated. We can examine it by using `x/w`
$5 = 0x80484a4 "abc"  
(gdb)x/w  0x80484a4  # Examine a word(4 bytes) starting from 0x80484a4
# Since it is in a little endian machine, "61" is at 0x80484a4.
# We can see that the 4th byte is "00" which represents "null" or "\0". 
0x80484a4:      0x00636261 
```



######      11.2 `frame`

```shell
(gdb) frame / f 1  # 调出一号栈帧，查看局部变量
```

###### 11.3 `printf` . 

```shell
(gdb)printf "i=%d, sum=%d\n", i, sum
```

Print two's complement value of  a number.

```shell
(gdb)printf "%d\n", 0xfffffff8  # It is -8. 
```



#####   12) Run `gdb` only.

```shell
$root>gdb  # Only input "gdb" in CLI
(gdb)print 200*300*400*500  # call print.
```

##### 13) `disassemble/disas` , `stepi` and `nexti`

 Disassemble a specified section of memory.

```shell
# By default, it disassemble the current function which surrounds the PC(program counter)
# of the selected frame.
(gdb)disassemble / disas
(gdb)disas sum	# Disassemble a function named "sum".
(gdb)disas 0x4004ed # Disassemble the function around the address of 0x4004ed.
(gdb)disas 0x400504, 0x40051e  # Disassemble code within specified range. 
```

To disassemble a specified function in a source code. Note that the address is interpreted as an expression, but not as a location as that in the `break` command. So if you want to disassemble a function name `pop` in `stack.c` , you should write as follows

```shell
(gdb)disassemble 'stack.c'::pop # Note there are quotation marks around 'stack.c'.
```

After disassembling, we can move a single instruction, namely to process one line of assembly code.

```shell
(gdb)stepi  # Execute one instruction
(gdb)stepi 4 # Execute 4 instructions
# It is like 'stepi', but proceeds through different function calls without stopping.
(gdb)nexti 
```

An Example of `nexti`

```assembly
  400efe:	48 83 ec 28          	sub    $0x28,%rsp
  400f02:	48 89 e6             	mov    %rsp,%rsi
=>400f05:	e8 52 05 00 00       	callq  40145c <read_six_numbers>
  400f0a:	83 3c 24 01          	cmpl   $0x1,(%rsp)
```

When an instruction in`0x400f05` is being executed to call a function named `read_six_numbers(...)`, if we move with `nexti`, the processor will move to `0x400f0a`, which means it only move within the current function. Whereas, if we move with `stepi`, it will step into `read_six_numbers(...)`

##### 14) `x`: examine memory

```shell
(gdb)x/8b input # 	
(gdb)x/1tb &i  #i is a variable    
(gdb)x/w  0xbfff780 # Examine 4 bytes of word starting from the address of 0xbfff780.
(gdb)x/wx 0x402470 # Examine 4 bytes of word starting 0x402470 in hexadecimal format. 
(gdb)x/w  $esp #Examine 4-byte words starting at the address in %esp.
(gdb)x/w  ($esp - 0xc) # Examine 4-byte word starting at 0xc(%esp).
(gdb)x/wd $esp  # Examine 4-byte word starting at the address in %esp in decimal format.
(gdb)x/wx $esp  # In hexdecimal format. 
(gdb)x/2w $esp  # Examine 2 4-yte words starting at the address in %esp.
(gdb)x/2wd $esp #Examine 2 4-yte words starting at the address in %esp in decimal format.
#Examine 8-byte words starting at the address in %esp.
(gdb)x/g $esp 
#Examine 8-yte words starting at the address in %esp in decimal format.
(gdb)x/gd $esp  
# Examine the address in %esp and print as offset from prvious.
(gdb)x/a $esp 
0xffffd2ac:     0x8048462 <__libc_csu_init+82>  # 0xffffd2ac is the content in %esp
# Examine a string stored at 0xffffcca8.
(gdb)x/s 0xffffcca8
# Examine first 20 opcode bytes of a function named "sum" ??
(gdb)x/20b sum
# Examine first 10 instructions of a function named "sum"
(gdb)x/10i sum
# Examine characters starting from an address
(gdb)x/c  ($rbx, $rax*1)   # An example from the bomb lab of CSAPP3e.
```

注意：```x/10b```命令在使用```watchpoint```之后不起作用，使用```break```的时候管用。

gdb以二进制形式打印一个byte的值

- `x`: This is the command to examine memory.
- `/1`: This specifies the number of units to display. In this case, we're specifying 1 unit.
- `tb`: These are format specifiers. `t` specifies that the memory should be interpreted as text, and `b` specifies that the output should be in byte format.
- `&i`: This is the address of the variable `i`. The `&` operator gives the address of a variable.

##### 15) `call` a function

We can call a function, which has been already in the running program, to test different arguments or so.

```shell
# Note to start execution before call a function.
(gdb)call add_range(1, 10)
```

##### 16) `define` a macro 

If we wanted to use a command frequently, we could use `define...end` to create a macro.

```shell
(gdb)define psum
Type commands for definition of "pisum".
End with a line saying just "end".
>printf "i = %d, sum = %d\n", i, sum   # Type the command you are using.
>end  # Type "end" to end this macro.
# Call this macro
(gdb)psum
```

##### 17) delete and clear

delete

```shell
(gdb)delete  # Delete all breakpoints, watchpoints, tracepoints or catchpoints. 
(gdb)delete breakpoints 1 # Delete one specific breakpoint.
(gdb)delete breakpoints 1 2 3 # Delete multiple specific breakpoint.
```

clear: clear break points at specified line or function. 

```shell
(gdb)clear 108  # clear a break point at line of 108.
# clear a break point at the addres of 0x400ec3. Don't forget asterisk
(gdb)clear *0x400ec3  
# If there are NOT any arguments, clear all the break points at the next instruction 
# to be executed in the seleted stack frame. 
(gdb)clear 
```



#### 3, scanf(...) in gdb

 Input arguments of `scanf(...)`

```shell
(gdb) n   # scanf() has been called. 
123       # input variables
```



#### 4, segment fault and `gdb`

segmentation_fault.c (see this code in `c-code/src/19_GDB`)  

```c
# include<stdio.h>
int main(void){	
	int i = 0;
    //segmentatioin falut, The '&' should be added before tha variable. Error occurs here.
	scanf("%d",i);  
	return 0;
}
```

`gdb` can help us to locate where an error, such as 'segment fault', happens when it is impossible to pinpoint it if an executable object is run. To illustrate, when the above is executed, there is only one message: Segmentation fault(cor dumped). It is implausible to where the error is from because in this case the error occurs in a system call. Whereas, we can run it in `gdb` without any breakpoints and use `bt(backtrace)` to find it. 

```shell
(gdb)run
# The "segmentation fault" occurs.
Program received signal SIGSEGV, Segmentation fault.
0x00007ffff7a69341 in __GI__IO_vfscanf () from /lib64/libc.so.6
# Then we input 'bt(backtrace)' and find where it occurs in our source code.
(gdb)bt
#0  0x00007ffff7a69341 in __GI__IO_vfscanf () from /lib64/libc.so.6
#1  0x00007ffff7a790b9 in __isoc99_scanf () from /lib64/libc.so.6  
#2  0x00000000004005cf in main () at segmentation_fault.c:11
#######
# We can find that a system call named "vfscanf()" is called by "scanf()" in our code. 
# Subsequently, the error is located. 
```

#### 5, command-line arguments

If there are command-line arguments to input when we run an executable object. For instance, `test.out abc`. We can input these arguments in `gdb` as follows.

```shell
# 1. Input arguments manually.
(gdb)r/run abc
# 2. I/O redirection example. We could also redirect input to a file as we do in CLI, 
# In CLI we can do this. 
./bomb < psol.txt  
# In gdb we can also do the same.
gdb bomb  # First of all, run 'gdb bomb'
(gdb)r/run < psol.txt  # Then redirect to the input file. 
# Or we can redirect an input file when start debugging.
(gdb)start < psol.txt
```

N.B. If we apply `r`  more than once in the same debugging session, there is no need to input these arguments once more; they are the default arguments next time. 

See the chapter 4.3.2 in [Guide to Faster, Less Frustrating Debugging.](https://heather.cs.ucdavis.edu/matloff/public_html/UnixAndC/CLanguage/Debug.html) 

#### 6, Recompiling the Source without Exiting `gdb`.

We don't have to exit a `gdb` session when we want to recompile the source. What we need to do is to open a new CLI  window and recompile the source; input `run/r` to restart the program.

Note we should tell `gdb` to relinquish our file being executed. Otherwise, the linker will tell us that the executable file is not accessible. (That has not been verified yet.)

```shell
(gdb)kill  # Terminate the current debugging session in gdb.
```



