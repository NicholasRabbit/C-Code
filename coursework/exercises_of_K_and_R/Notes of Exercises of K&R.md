### Chapter 1 

#### Exercise 1.16 

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

