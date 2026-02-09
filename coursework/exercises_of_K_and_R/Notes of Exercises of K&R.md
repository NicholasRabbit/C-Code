### Chapter 1 

#### Exercise 1.16 

The following assembly is generated with `gcc -m32 -g xxx.c` at a `x86-64` machine because I am familiar with AT&T-syntax assembly in a `IA32` machine. 

```assembly
# get_line(line, MAXLINE)
080484af <get_line>:
 80484af:	55                   	push   %ebp
 80484b0:	89 e5                	mov    %esp,%ebp
 80484b2:	83 ec 18             	sub    $0x18,%esp
 80484b5:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 80484bc:	eb 11                	jmp    80484cf <get_line+0x20>
 80484be:	8b 55 f4             	mov    -0xc(%ebp),%edx
 # The array "line" starts at '0x8(%ebp)'.
 80484c1:	8b 45 08             	mov    0x8(%ebp),%eax
 80484c4:	01 c2                	add    %eax,%edx
 80484c6:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80484c9:	88 02                	mov    %al,(%edx)
 80484cb:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 80484cf:	e8 2c fe ff ff       	call   8048300 <getchar@plt>
 80484d4:	89 45 f0             	mov    %eax,-0x10(%ebp)
 # The hexadecimal value of EOF is '-1', namely 0xffffffff.
 80484d7:	83 7d f0 ff          	cmpl   $0xffffffff,-0x10(%ebp)
 80484db:	74 06                	je     80484e3 <get_line+0x34>
 # The hexadecimal value of '\n' is 0xa. 
 80484dd:	83 7d f0 0a          	cmpl   $0xa,-0x10(%ebp)
 80484e1:	75 db                	jne    80484be <get_line+0xf>
 80484e3:	83 7d f0 0a          	cmpl   $0xa,-0x10(%ebp)
 80484e7:	75 11                	jne    80484fa <get_line+0x4b>
 80484e9:	8b 55 f4             	mov    -0xc(%ebp),%edx
 80484ec:	8b 45 08             	mov    0x8(%ebp),%eax
 80484ef:	01 c2                	add    %eax,%edx
 80484f1:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80484f4:	88 02                	mov    %al,(%edx)
 80484f6:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 80484fa:	8b 55 f4             	mov    -0xc(%ebp),%edx
 80484fd:	8b 45 08             	mov    0x8(%ebp),%eax
 8048500:	01 d0                	add    %edx,%eax
 8048502:	c6 00 00             	movb   $0x0,(%eax)
 8048505:	8b 45 f4             	mov    -0xc(%ebp),%eax
 8048508:	c9                   	leave  
 8048509:	c3                   	ret    
```

main

```assembly
0804843d <main>:
 804843d:	55                   	push   %ebp
 804843e:	89 e5                	mov    %esp,%ebp
 8048440:	83 e4 f0             	and    $0xfffffff0,%esp
 8048443:	83 ec 30             	sub    $0x30,%esp
 8048446:	c7 44 24 2c 00 00 00 	movl   $0x0,0x2c(%esp)
 804844d:	00 
 804844e:	eb 26                	jmp    8048476 <main+0x39>
 8048450:	8b 44 24 28          	mov    0x28(%esp),%eax
 8048454:	3b 44 24 2c          	cmp    0x2c(%esp),%eax
 8048458:	7e 1c                	jle    8048476 <main+0x39>
 804845a:	8b 44 24 28          	mov    0x28(%esp),%eax
 804845e:	89 44 24 2c          	mov    %eax,0x2c(%esp)
 8048462:	8d 44 24 1e          	lea    0x1e(%esp),%eax
 8048466:	89 44 24 04          	mov    %eax,0x4(%esp)
 804846a:	8d 44 24 14          	lea    0x14(%esp),%eax
 804846e:	89 04 24             	mov    %eax,(%esp)
 8048471:	e8 94 00 00 00       	call   804850a <copy>
 8048476:	c7 44 24 04 0a 00 00 	movl   $0xa,0x4(%esp)
 804847d:	00 
 804847e:	8d 44 24 1e          	lea    0x1e(%esp),%eax
 8048482:	89 04 24             	mov    %eax,(%esp)
 8048485:	e8 25 00 00 00       	call   80484af <get_line>
 804848a:	89 44 24 28          	mov    %eax,0x28(%esp)
 804848e:	83 7c 24 28 00       	cmpl   $0x0,0x28(%esp)
 8048493:	7f bb                	jg     8048450 <main+0x13>
 8048495:	83 7c 24 2c 00       	cmpl   $0x0,0x2c(%esp)
 804849a:	7e 0c                	jle    80484a8 <main+0x6b>
 804849c:	8d 44 24 14          	lea    0x14(%esp),%eax
 80484a0:	89 04 24             	mov    %eax,(%esp)
 80484a3:	e8 68 fe ff ff       	call   8048310 <puts@plt>
 80484a8:	b8 00 00 00 00       	mov    $0x0,%eax
 80484ad:	c9                   	leave  
 80484ae:	c3                   	ret    
```

#### Exercise 1.20

(1) What is a symbolic parameter?

```c
#define COLUMN 8  // COLUMN is a symbolic parameter or symbolic constant. 
```

(2) `tab` doesn't necessarily move 4 columns or 8 columns(if it is set to 8 by default). It doesn't move specific columns; if a program encounters a `\t`, it doesn't print fixed number of spaces but prints enough spaces to reach the next `tab`.  As an illustration: 

```c
// Tabstops are 4 columns by default. 
ab	|  // 'tab' moves 2 columns.
a	|  //  'tab' moves 2 columns.
abcd	| // 4 spaces
abcde	| // 3 spaces.
```

Consequently, although `tabstop` is set to 4 columns by default, it is not always 4. To realise that is the key to tackle this problem. 

If there is only 1 character, the columns of a `tabstop` is 3.  (4 - 2).

If there are 2 characters, the columns of a `tabstop` is 2.  (4 - 2).

Thus, we conclude that the columns = 4 - (n % 4), n is the number of non-blank characters. 

