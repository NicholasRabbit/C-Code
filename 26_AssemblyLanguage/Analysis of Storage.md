### Chapter  19  Lesson 3 

#### 一,  变量存储布局分析

对应个人代码目录：../26_AssemblyLanguage/4_StorageOfVariables

```c
const int A = 10;
int a = 20;
static int b = 30;
int c;
int main(void){
   
	static int a = 40;
	char b[] = "Hello C";
	register int c = 50;

	printf("Hello C %d\n", c);

	return 0;
}
```



关键词解释。

```c
const  //所修饰的变量不可修改
static //1,在函数外，即在{}外使用，表示所修饰的变量是local的，只能在本文件内使用
       //2,在函数内使用，即在{}内，并不是像一般局部变量一样在函数调用时分配，而是像全局变量一样静态分配
       //  但是其作用域和局部变量一样也是在函数内。
register  //修饰的变量直接入栈。    
```



1, 首先执行`readelf -W -a TestStorage.out`, 展示ELF文件信息，可以看到变量A如下所示。显示的都是16进制。地址是0x400600，int A 占4个byte，这个是它的起始地址，代表其内存地址。

```shell
    63: 0000000000400570   101 FUNC    GLOBAL DEFAULT   13 __libc_csu_init
    64: 0000000000400600     4 OBJECT  GLOBAL DEFAULT   15 A   #A的地址
    65: 0000000000601048     0 NOTYPE  GLOBAL DEFAULT   25 _end
    66: 0000000000400440     0 FUNC    GLOBAL DEFAULT   13 _start
```

2, 然后向上翻可以看到在Section Headers下面的数据，

```txt
Section Headers:
[Nr] Name              Type            Address          Off    Size   ES Flg Lk Inf Al
...
[14] .fini             PROGBITS        00000000004005e4 0005e4 000009 00  AX  0   0  4
[15] .rodata           PROGBITS        00000000004005f0 0005f0 000020 00   A  0   0  8
...
[24] .data             PROGBITS        0000000000601030 001030 000010 00  WA  0   0  4
[25] .bss              NOBITS          0000000000601040 001040 000008 00  WA  0   0  4
```

可以看到A位于`.rodata`行。因为0x5f0 + 20 = 0x610，所以0x600在这个范围内。

3，执行`hexdump -C TestStorage.out`打印文件的全部字节，结果全部都是16进制的。

```shell
000005e0  f3 c3 00 00 48 83 ec 08  48 83 c4 08 c3 00 00 00  |....H...H.......|
000005f0  01 00 02 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000600  0a 00 00 00 48 65 6c 6c  6f 20 43 20 25 64 0a 00  |....Hello C %d..| #A和Hello C
00000610  01 1b 03 3b 34 00 00 00  05 00 00 00 f0 fd ff ff  |...;4...........|
00000620  80 00 00 00 30 fe ff ff  50 00 00 00 1d ff ff ff  |....0...P.......|
```

- 注意：这里的地址仅取上面地址的后三位。
- 可以看到0x0a = 10就是代表A的值，后面的三个`00`没有用上，一共占4个字节。然后`48 65 6c 6c  6f 20 43`代表的是`char b[] = "Hello C"`。这里的`b`的地址就是数组开头`H`的地址。

- 在ELF文件中`.rodata`和`.text`段是只读的，程序加载时通常会把它们放到一个Segment里，防止改写。`const int A=10`和字符串"Hello C"都是只读的，所以放到这个段里。
  rodata = read only data。汇编里使用到这两个段了，参照汇编代码理解。
- `.data`和`.bss`是可读写段，系统把他们放到一个Segment里，可读写的变量放到这个段里。
  `.bss`段在文件中不占存储空间，在加载时用0填充。(全局变量的默认值在这里存储？？)

```shell
 Section to Segment mapping:
  Segment Sections...
   00     
   01     .interp 
   
   02     .interp .note.ABI-tag .note.gnu.build-id .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rela.dyn .rela.plt .init .plt .text .fini .rodata .eh_frame_hdr .eh_frame 
   
   03     .init_array .fini_array .jcr .dynamic .got .got.plt .data .bss 
```



4，`int a=20; static int b =30; int c;`（函数外）和`{static int a = 40}（函数内）`存储布局

```shell
# readelf result    
    42: 0000000000601038     4 OBJECT  LOCAL  DEFAULT   24 b
    43: 000000000060103c     4 OBJECT  LOCAL  DEFAULT   24 a.2183 #这个就是main函数内的变量a,加.2183是为了区分不同函数内的同名变量。
    ...
    67: 0000000000601044     4 OBJECT  GLOBAL DEFAULT   25 c
    68: 0000000000601034     4 OBJECT  GLOBAL DEFAULT   24 a
```

```shell
# hexdump result
00001030  00 00 00 00 14 00 00 00  1e 00 00 00 28 00 00 00  |............(...| 
00001040  47 43 43 3a 20 28 47 4e  55 29 20 34 2e 38 2e 35  |GCC: (GNU) 4.8.5|
```

- 可以看到b的作用域是"LOCAL"说明static 修饰的函数外的变量只能在本文件内使用，而a对应的是"GLOBAL"说明它可以被全局使用，c也一样。
- 这几个非const修饰的变量在.data和.dss段，这两个段是可读写的。
- 根据地址找hexdump显示的内存布局。
  - a是0x1034对应`hexdump: 1030  ... 14 00 00 00` , 而0x14=20。
  - b是0x1038，对应`1e 00 00 00` , 0x1e=30。
  - a.2183是0x103c对应`28 00 00 00`, 0x28=40。

5，`char b[] = "Hello C"`内存布局见3，这里分析反汇编代码。

```shell
int main(void){
	....
	static int a = 40;   
	char b[] = "Hello C";
  #下面显示的就是以上C代码对应的汇编代码
  #注意"Hello C"是倒着入栈的，对应寄存器地址是由高到低减小，0x43 20 ...="C olleH"(ANSI)
  #hexdump打印的是硬盘上的布局是正序显示的，这里是register里的布局。
  400536:	48 b8 48 65 6c 6c 6f 	movabs $0x43206f6c6c6548,%rax  #把字符串存入%rax
  40053d:	20 43 00  #上一行从第二个48 65..43 00即"Hello C\0"，00就是截止符号\0
  
  400540:	48 89 45 e0          	mov    %rax,-0x20(%rbp)  #%rax入栈

  register int c = 50;
  # register关键词修饰的变量直接入寄存器，而源代码中static int a 就没有显示在反编译代码里，
  #说明没有直接入寄存器	
  400544:	bb 32 00 00 00       	mov    $0x32,%ebx  

	printf("Hello C %d\n", c);
  400549:	89 de                	mov    %ebx,%esi
  40054b:	bf 04 06 40 00       	mov    $0x400604,%edi
  400550:	b8 00 00 00 00       	mov    $0x0,%eax
  400555:	e8 b6 fe ff ff       	callq  400410 <printf@plt>

	return 0;
  40055a:	b8 00 00 00 00       	mov    $0x0,%eax
}
```

