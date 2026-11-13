
test_external.out:     file format elf32-i386


Disassembly of section .init:

0804828c <_init>:
 804828c:	53                   	push   %ebx
 804828d:	83 ec 08             	sub    $0x8,%esp
 8048290:	e8 7b 00 00 00       	call   8048310 <__x86.get_pc_thunk.bx>
 8048295:	81 c3 6b 1d 00 00    	add    $0x1d6b,%ebx
 804829b:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80482a1:	85 c0                	test   %eax,%eax
 80482a3:	74 05                	je     80482aa <_init+0x1e>
 80482a5:	e8 26 00 00 00       	call   80482d0 <.plt.got>
 80482aa:	83 c4 08             	add    $0x8,%esp
 80482ad:	5b                   	pop    %ebx
 80482ae:	c3                   	ret    

Disassembly of section .plt:

080482b0 <.plt>:
 80482b0:	ff 35 04 a0 04 08    	pushl  0x804a004
 80482b6:	ff 25 08 a0 04 08    	jmp    *0x804a008
 80482bc:	00 00                	add    %al,(%eax)
	...

080482c0 <__libc_start_main@plt>:
 80482c0:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 80482c6:	68 00 00 00 00       	push   $0x0
 80482cb:	e9 e0 ff ff ff       	jmp    80482b0 <.plt>

Disassembly of section .plt.got:

080482d0 <.plt.got>:
 80482d0:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 80482d6:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

080482e0 <_start>:
 80482e0:	31 ed                	xor    %ebp,%ebp
 80482e2:	5e                   	pop    %esi
 80482e3:	89 e1                	mov    %esp,%ecx
 80482e5:	83 e4 f0             	and    $0xfffffff0,%esp
 80482e8:	50                   	push   %eax
 80482e9:	54                   	push   %esp
 80482ea:	52                   	push   %edx
 80482eb:	68 90 84 04 08       	push   $0x8048490
 80482f0:	68 20 84 04 08       	push   $0x8048420
 80482f5:	51                   	push   %ecx
 80482f6:	56                   	push   %esi
 80482f7:	68 ef 83 04 08       	push   $0x80483ef
 80482fc:	e8 bf ff ff ff       	call   80482c0 <__libc_start_main@plt>
 8048301:	f4                   	hlt    
 8048302:	66 90                	xchg   %ax,%ax
 8048304:	66 90                	xchg   %ax,%ax
 8048306:	66 90                	xchg   %ax,%ax
 8048308:	66 90                	xchg   %ax,%ax
 804830a:	66 90                	xchg   %ax,%ax
 804830c:	66 90                	xchg   %ax,%ax
 804830e:	66 90                	xchg   %ax,%ax

08048310 <__x86.get_pc_thunk.bx>:
 8048310:	8b 1c 24             	mov    (%esp),%ebx
 8048313:	c3                   	ret    
 8048314:	66 90                	xchg   %ax,%ax
 8048316:	66 90                	xchg   %ax,%ax
 8048318:	66 90                	xchg   %ax,%ax
 804831a:	66 90                	xchg   %ax,%ax
 804831c:	66 90                	xchg   %ax,%ax
 804831e:	66 90                	xchg   %ax,%ax

08048320 <deregister_tm_clones>:
 8048320:	b8 17 a0 04 08       	mov    $0x804a017,%eax
 8048325:	2d 14 a0 04 08       	sub    $0x804a014,%eax
 804832a:	83 f8 06             	cmp    $0x6,%eax
 804832d:	77 01                	ja     8048330 <deregister_tm_clones+0x10>
 804832f:	c3                   	ret    
 8048330:	b8 00 00 00 00       	mov    $0x0,%eax
 8048335:	85 c0                	test   %eax,%eax
 8048337:	74 f6                	je     804832f <deregister_tm_clones+0xf>
 8048339:	55                   	push   %ebp
 804833a:	89 e5                	mov    %esp,%ebp
 804833c:	83 ec 18             	sub    $0x18,%esp
 804833f:	c7 04 24 14 a0 04 08 	movl   $0x804a014,(%esp)
 8048346:	ff d0                	call   *%eax
 8048348:	c9                   	leave  
 8048349:	c3                   	ret    
 804834a:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

08048350 <register_tm_clones>:
 8048350:	b8 14 a0 04 08       	mov    $0x804a014,%eax
 8048355:	2d 14 a0 04 08       	sub    $0x804a014,%eax
 804835a:	c1 f8 02             	sar    $0x2,%eax
 804835d:	89 c2                	mov    %eax,%edx
 804835f:	c1 ea 1f             	shr    $0x1f,%edx
 8048362:	01 d0                	add    %edx,%eax
 8048364:	d1 f8                	sar    %eax
 8048366:	75 01                	jne    8048369 <register_tm_clones+0x19>
 8048368:	c3                   	ret    
 8048369:	ba 00 00 00 00       	mov    $0x0,%edx
 804836e:	85 d2                	test   %edx,%edx
 8048370:	74 f6                	je     8048368 <register_tm_clones+0x18>
 8048372:	55                   	push   %ebp
 8048373:	89 e5                	mov    %esp,%ebp
 8048375:	83 ec 18             	sub    $0x18,%esp
 8048378:	89 44 24 04          	mov    %eax,0x4(%esp)
 804837c:	c7 04 24 14 a0 04 08 	movl   $0x804a014,(%esp)
 8048383:	ff d2                	call   *%edx
 8048385:	c9                   	leave  
 8048386:	c3                   	ret    
 8048387:	89 f6                	mov    %esi,%esi
 8048389:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

08048390 <__do_global_dtors_aux>:
 8048390:	80 3d 14 a0 04 08 00 	cmpb   $0x0,0x804a014
 8048397:	75 13                	jne    80483ac <__do_global_dtors_aux+0x1c>
 8048399:	55                   	push   %ebp
 804839a:	89 e5                	mov    %esp,%ebp
 804839c:	83 ec 08             	sub    $0x8,%esp
 804839f:	e8 7c ff ff ff       	call   8048320 <deregister_tm_clones>
 80483a4:	c6 05 14 a0 04 08 01 	movb   $0x1,0x804a014
 80483ab:	c9                   	leave  
 80483ac:	f3 c3                	repz ret 
 80483ae:	66 90                	xchg   %ax,%ax

080483b0 <frame_dummy>:
 80483b0:	a1 10 9f 04 08       	mov    0x8049f10,%eax
 80483b5:	85 c0                	test   %eax,%eax
 80483b7:	74 1f                	je     80483d8 <frame_dummy+0x28>
 80483b9:	b8 00 00 00 00       	mov    $0x0,%eax
 80483be:	85 c0                	test   %eax,%eax
 80483c0:	74 16                	je     80483d8 <frame_dummy+0x28>
 80483c2:	55                   	push   %ebp
 80483c3:	89 e5                	mov    %esp,%ebp
 80483c5:	83 ec 18             	sub    $0x18,%esp
 80483c8:	c7 04 24 10 9f 04 08 	movl   $0x8049f10,(%esp)
 80483cf:	ff d0                	call   *%eax
 80483d1:	c9                   	leave  
 80483d2:	e9 79 ff ff ff       	jmp    8048350 <register_tm_clones>
 80483d7:	90                   	nop
 80483d8:	e9 73 ff ff ff       	jmp    8048350 <register_tm_clones>

080483dd <add>:
#include <stdio.h>

int i, j;

int add()
{
 80483dd:	55                   	push   %ebp
 80483de:	89 e5                	mov    %esp,%ebp
	return i + j;
 80483e0:	8b 15 1c a0 04 08    	mov    0x804a01c,%edx
 80483e6:	a1 18 a0 04 08       	mov    0x804a018,%eax
 80483eb:	01 d0                	add    %edx,%eax
}
 80483ed:	5d                   	pop    %ebp
 80483ee:	c3                   	ret    

080483ef <main>:


int main(int argc, char *argv[])
{
 80483ef:	55                   	push   %ebp
 80483f0:	89 e5                	mov    %esp,%ebp
	
	i = 1;
 80483f2:	c7 05 1c a0 04 08 01 	movl   $0x1,0x804a01c
 80483f9:	00 00 00 
	j = 2;
 80483fc:	c7 05 18 a0 04 08 02 	movl   $0x2,0x804a018
 8048403:	00 00 00 
	add();
 8048406:	e8 d2 ff ff ff       	call   80483dd <add>
	return 0;
 804840b:	b8 00 00 00 00       	mov    $0x0,%eax
}
 8048410:	5d                   	pop    %ebp
 8048411:	c3                   	ret    
 8048412:	66 90                	xchg   %ax,%ax
 8048414:	66 90                	xchg   %ax,%ax
 8048416:	66 90                	xchg   %ax,%ax
 8048418:	66 90                	xchg   %ax,%ax
 804841a:	66 90                	xchg   %ax,%ax
 804841c:	66 90                	xchg   %ax,%ax
 804841e:	66 90                	xchg   %ax,%ax

08048420 <__libc_csu_init>:
 8048420:	55                   	push   %ebp
 8048421:	57                   	push   %edi
 8048422:	31 ff                	xor    %edi,%edi
 8048424:	56                   	push   %esi
 8048425:	53                   	push   %ebx
 8048426:	e8 e5 fe ff ff       	call   8048310 <__x86.get_pc_thunk.bx>
 804842b:	81 c3 d5 1b 00 00    	add    $0x1bd5,%ebx
 8048431:	83 ec 1c             	sub    $0x1c,%esp
 8048434:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 8048438:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804843e:	e8 49 fe ff ff       	call   804828c <_init>
 8048443:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8048449:	29 c6                	sub    %eax,%esi
 804844b:	c1 fe 02             	sar    $0x2,%esi
 804844e:	85 f6                	test   %esi,%esi
 8048450:	74 27                	je     8048479 <__libc_csu_init+0x59>
 8048452:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048458:	8b 44 24 38          	mov    0x38(%esp),%eax
 804845c:	89 2c 24             	mov    %ebp,(%esp)
 804845f:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048463:	8b 44 24 34          	mov    0x34(%esp),%eax
 8048467:	89 44 24 04          	mov    %eax,0x4(%esp)
 804846b:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 8048472:	83 c7 01             	add    $0x1,%edi
 8048475:	39 f7                	cmp    %esi,%edi
 8048477:	75 df                	jne    8048458 <__libc_csu_init+0x38>
 8048479:	83 c4 1c             	add    $0x1c,%esp
 804847c:	5b                   	pop    %ebx
 804847d:	5e                   	pop    %esi
 804847e:	5f                   	pop    %edi
 804847f:	5d                   	pop    %ebp
 8048480:	c3                   	ret    
 8048481:	eb 0d                	jmp    8048490 <__libc_csu_fini>
 8048483:	90                   	nop
 8048484:	90                   	nop
 8048485:	90                   	nop
 8048486:	90                   	nop
 8048487:	90                   	nop
 8048488:	90                   	nop
 8048489:	90                   	nop
 804848a:	90                   	nop
 804848b:	90                   	nop
 804848c:	90                   	nop
 804848d:	90                   	nop
 804848e:	90                   	nop
 804848f:	90                   	nop

08048490 <__libc_csu_fini>:
 8048490:	f3 c3                	repz ret 

Disassembly of section .fini:

08048494 <_fini>:
 8048494:	53                   	push   %ebx
 8048495:	83 ec 08             	sub    $0x8,%esp
 8048498:	e8 73 fe ff ff       	call   8048310 <__x86.get_pc_thunk.bx>
 804849d:	81 c3 63 1b 00 00    	add    $0x1b63,%ebx
 80484a3:	83 c4 08             	add    $0x8,%esp
 80484a6:	5b                   	pop    %ebx
 80484a7:	c3                   	ret    
