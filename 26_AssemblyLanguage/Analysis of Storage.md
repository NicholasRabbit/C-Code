### Chapter  19  Lesson 3 

#### 一,  变量存储布局分析

对应个人代码目录：../26_AssemblyLanguage/4_StorageOfVariables

1, 首先执行`readelf -W -a TestStorage.out`, 展示ELF文件信息，可以看到变量A如下所示。显示的都是16进制。地址是0x400600，int A 占4个byte，这个是它的起始地址，代表其内存地址。

```shell
	61: 00000000004005f8     0 OBJECT  GLOBAL HIDDEN    15 __dso_handle
    62: 00000000004005f0     4 OBJECT  GLOBAL DEFAULT   15 _IO_stdin_used
    63: 0000000000400570   101 FUNC    GLOBAL DEFAULT   13 __libc_csu_init
    64: 0000000000400600     4 OBJECT  GLOBAL DEFAULT   15 A   #A的地址
    65: 0000000000601048     0 NOTYPE  GLOBAL DEFAULT   25 _end
    66: 0000000000400440     0 FUNC    GLOBAL DEFAULT   13 _start
```



2, 然后向上翻可以看到在Section Headers下面的数据，可以看到A位于`.rodata`行。
因为0x5f0 + 20 = 0x610，所以0x600在这个范围内。

```txt
Section Headers:
[Nr] Name              Type            Address          Off    Size   ES Flg Lk Inf Al
[12] .plt              PROGBITS        0000000000400400 000400 000040 10  AX  0   0 16
[13] .text             PROGBITS        0000000000400440 000440 0001a2 00  AX  0   0 16
[14] .fini             PROGBITS        00000000004005e4 0005e4 000009 00  AX  0   0  4
[15] .rodata           PROGBITS        00000000004005f0 0005f0 000020 00   A  0   0  8
[16] .eh_frame_hdr     PROGBITS        0000000000400 000610 000034 00   A  0   0  4
[17] .eh_frame         PROGBITS        0000000000400648 000648 0000f4 00   A  0   0  8
[18] .init_array       INIT_ARRAY      0000000000600e10 000e10 000008 08  WA  0   0  8
```

3，执行`hexdump -C TestStorage.out`打印文件的全部字节，结果全部都是16进制的。

```shell
000005e0  f3 c3 00 00 48 83 ec 08  48 83 c4 08 c3 00 00 00  |....H...H.......|
000005f0  01 00 02 00 00 00 00 00  00 00 00 00 00 00 00 00  |................|
00000600  0a 00 00 00 48 65 6c 6c  6f 20 43 20 25 64 0a 00  |....Hello C %d..| #A
00000610  01 1b 03 3b 34 00 00 00  05 00 00 00 f0 fd ff ff  |...;4...........|
00000620  80 00 00 00 30 fe ff ff  50 00 00 00 1d ff ff ff  |....0...P.......|
```

可以看到0x0a = 10就是代表A的值，后面的三个`00`没有用上，一共占4个字节。然后`48 65 6c 6c  6f 20 43`代表的是"Hello C"