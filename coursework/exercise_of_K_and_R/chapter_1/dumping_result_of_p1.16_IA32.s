
test_16.out:     file format elf32-i386


Disassembly of section .init:

080482cc <_init>:
 80482cc:	53                   	push   %ebx
 80482cd:	83 ec 08             	sub    $0x8,%esp
 80482d0:	e8 9b 00 00 00       	call   8048370 <__x86.get_pc_thunk.bx>
 80482d5:	81 c3 2b 1d 00 00    	add    $0x1d2b,%ebx
 80482db:	8b 83 fc ff ff ff    	mov    -0x4(%ebx),%eax
 80482e1:	85 c0                	test   %eax,%eax
 80482e3:	74 05                	je     80482ea <_init+0x1e>
 80482e5:	e8 46 00 00 00       	call   8048330 <.plt.got>
 80482ea:	83 c4 08             	add    $0x8,%esp
 80482ed:	5b                   	pop    %ebx
 80482ee:	c3                   	ret    

Disassembly of section .plt:

080482f0 <.plt>:
 80482f0:	ff 35 04 a0 04 08    	pushl  0x804a004
 80482f6:	ff 25 08 a0 04 08    	jmp    *0x804a008
 80482fc:	00 00                	add    %al,(%eax)
	...

08048300 <getchar@plt>:
 8048300:	ff 25 0c a0 04 08    	jmp    *0x804a00c
 8048306:	68 00 00 00 00       	push   $0x0
 804830b:	e9 e0 ff ff ff       	jmp    80482f0 <.plt>

08048310 <puts@plt>:
 8048310:	ff 25 10 a0 04 08    	jmp    *0x804a010
 8048316:	68 08 00 00 00       	push   $0x8
 804831b:	e9 d0 ff ff ff       	jmp    80482f0 <.plt>

08048320 <__libc_start_main@plt>:
 8048320:	ff 25 14 a0 04 08    	jmp    *0x804a014
 8048326:	68 10 00 00 00       	push   $0x10
 804832b:	e9 c0 ff ff ff       	jmp    80482f0 <.plt>

Disassembly of section .plt.got:

08048330 <.plt.got>:
 8048330:	ff 25 fc 9f 04 08    	jmp    *0x8049ffc
 8048336:	66 90                	xchg   %ax,%ax

Disassembly of section .text:

08048340 <_start>:
 8048340:	31 ed                	xor    %ebp,%ebp
 8048342:	5e                   	pop    %esi
 8048343:	89 e1                	mov    %esp,%ecx
 8048345:	83 e4 f0             	and    $0xfffffff0,%esp
 8048348:	50                   	push   %eax
 8048349:	54                   	push   %esp
 804834a:	52                   	push   %edx
 804834b:	68 b0 85 04 08       	push   $0x80485b0
 8048350:	68 40 85 04 08       	push   $0x8048540
 8048355:	51                   	push   %ecx
 8048356:	56                   	push   %esi
 8048357:	68 3d 84 04 08       	push   $0x804843d
 804835c:	e8 bf ff ff ff       	call   8048320 <__libc_start_main@plt>
 8048361:	f4                   	hlt    
 8048362:	66 90                	xchg   %ax,%ax
 8048364:	66 90                	xchg   %ax,%ax
 8048366:	66 90                	xchg   %ax,%ax
 8048368:	66 90                	xchg   %ax,%ax
 804836a:	66 90                	xchg   %ax,%ax
 804836c:	66 90                	xchg   %ax,%ax
 804836e:	66 90                	xchg   %ax,%ax

08048370 <__x86.get_pc_thunk.bx>:
 8048370:	8b 1c 24             	mov    (%esp),%ebx
 8048373:	c3                   	ret    
 8048374:	66 90                	xchg   %ax,%ax
 8048376:	66 90                	xchg   %ax,%ax
 8048378:	66 90                	xchg   %ax,%ax
 804837a:	66 90                	xchg   %ax,%ax
 804837c:	66 90                	xchg   %ax,%ax
 804837e:	66 90                	xchg   %ax,%ax

08048380 <deregister_tm_clones>:
 8048380:	b8 1f a0 04 08       	mov    $0x804a01f,%eax
 8048385:	2d 1c a0 04 08       	sub    $0x804a01c,%eax
 804838a:	83 f8 06             	cmp    $0x6,%eax
 804838d:	77 01                	ja     8048390 <deregister_tm_clones+0x10>
 804838f:	c3                   	ret    
 8048390:	b8 00 00 00 00       	mov    $0x0,%eax
 8048395:	85 c0                	test   %eax,%eax
 8048397:	74 f6                	je     804838f <deregister_tm_clones+0xf>
 8048399:	55                   	push   %ebp
 804839a:	89 e5                	mov    %esp,%ebp
 804839c:	83 ec 18             	sub    $0x18,%esp
 804839f:	c7 04 24 1c a0 04 08 	movl   $0x804a01c,(%esp)
 80483a6:	ff d0                	call   *%eax
 80483a8:	c9                   	leave  
 80483a9:	c3                   	ret    
 80483aa:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi

080483b0 <register_tm_clones>:
 80483b0:	b8 1c a0 04 08       	mov    $0x804a01c,%eax
 80483b5:	2d 1c a0 04 08       	sub    $0x804a01c,%eax
 80483ba:	c1 f8 02             	sar    $0x2,%eax
 80483bd:	89 c2                	mov    %eax,%edx
 80483bf:	c1 ea 1f             	shr    $0x1f,%edx
 80483c2:	01 d0                	add    %edx,%eax
 80483c4:	d1 f8                	sar    %eax
 80483c6:	75 01                	jne    80483c9 <register_tm_clones+0x19>
 80483c8:	c3                   	ret    
 80483c9:	ba 00 00 00 00       	mov    $0x0,%edx
 80483ce:	85 d2                	test   %edx,%edx
 80483d0:	74 f6                	je     80483c8 <register_tm_clones+0x18>
 80483d2:	55                   	push   %ebp
 80483d3:	89 e5                	mov    %esp,%ebp
 80483d5:	83 ec 18             	sub    $0x18,%esp
 80483d8:	89 44 24 04          	mov    %eax,0x4(%esp)
 80483dc:	c7 04 24 1c a0 04 08 	movl   $0x804a01c,(%esp)
 80483e3:	ff d2                	call   *%edx
 80483e5:	c9                   	leave  
 80483e6:	c3                   	ret    
 80483e7:	89 f6                	mov    %esi,%esi
 80483e9:	8d bc 27 00 00 00 00 	lea    0x0(%edi,%eiz,1),%edi

080483f0 <__do_global_dtors_aux>:
 80483f0:	80 3d 1c a0 04 08 00 	cmpb   $0x0,0x804a01c
 80483f7:	75 13                	jne    804840c <__do_global_dtors_aux+0x1c>
 80483f9:	55                   	push   %ebp
 80483fa:	89 e5                	mov    %esp,%ebp
 80483fc:	83 ec 08             	sub    $0x8,%esp
 80483ff:	e8 7c ff ff ff       	call   8048380 <deregister_tm_clones>
 8048404:	c6 05 1c a0 04 08 01 	movb   $0x1,0x804a01c
 804840b:	c9                   	leave  
 804840c:	f3 c3                	repz ret 
 804840e:	66 90                	xchg   %ax,%ax

08048410 <frame_dummy>:
 8048410:	a1 10 9f 04 08       	mov    0x8049f10,%eax
 8048415:	85 c0                	test   %eax,%eax
 8048417:	74 1f                	je     8048438 <frame_dummy+0x28>
 8048419:	b8 00 00 00 00       	mov    $0x0,%eax
 804841e:	85 c0                	test   %eax,%eax
 8048420:	74 16                	je     8048438 <frame_dummy+0x28>
 8048422:	55                   	push   %ebp
 8048423:	89 e5                	mov    %esp,%ebp
 8048425:	83 ec 18             	sub    $0x18,%esp
 8048428:	c7 04 24 10 9f 04 08 	movl   $0x8049f10,(%esp)
 804842f:	ff d0                	call   *%eax
 8048431:	c9                   	leave  
 8048432:	e9 79 ff ff ff       	jmp    80483b0 <register_tm_clones>
 8048437:	90                   	nop
 8048438:	e9 73 ff ff ff       	jmp    80483b0 <register_tm_clones>

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

080484af <get_line>:
 80484af:	55                   	push   %ebp
 80484b0:	89 e5                	mov    %esp,%ebp
 80484b2:	83 ec 18             	sub    $0x18,%esp
 80484b5:	c7 45 f4 00 00 00 00 	movl   $0x0,-0xc(%ebp)
 80484bc:	eb 11                	jmp    80484cf <get_line+0x20>
 80484be:	8b 55 f4             	mov    -0xc(%ebp),%edx
 80484c1:	8b 45 08             	mov    0x8(%ebp),%eax
 80484c4:	01 c2                	add    %eax,%edx
 80484c6:	8b 45 f0             	mov    -0x10(%ebp),%eax
 80484c9:	88 02                	mov    %al,(%edx)
 80484cb:	83 45 f4 01          	addl   $0x1,-0xc(%ebp)
 80484cf:	e8 2c fe ff ff       	call   8048300 <getchar@plt>
 80484d4:	89 45 f0             	mov    %eax,-0x10(%ebp)
 80484d7:	83 7d f0 ff          	cmpl   $0xffffffff,-0x10(%ebp)
 80484db:	74 06                	je     80484e3 <get_line+0x34>
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

0804850a <copy>:
 804850a:	55                   	push   %ebp
 804850b:	89 e5                	mov    %esp,%ebp
 804850d:	83 ec 10             	sub    $0x10,%esp
 8048510:	c7 45 fc 00 00 00 00 	movl   $0x0,-0x4(%ebp)
 8048517:	eb 04                	jmp    804851d <copy+0x13>
 8048519:	83 45 fc 01          	addl   $0x1,-0x4(%ebp)
 804851d:	8b 55 fc             	mov    -0x4(%ebp),%edx
 8048520:	8b 45 08             	mov    0x8(%ebp),%eax
 8048523:	01 d0                	add    %edx,%eax
 8048525:	8b 4d fc             	mov    -0x4(%ebp),%ecx
 8048528:	8b 55 0c             	mov    0xc(%ebp),%edx
 804852b:	01 ca                	add    %ecx,%edx
 804852d:	0f b6 12             	movzbl (%edx),%edx
 8048530:	88 10                	mov    %dl,(%eax)
 8048532:	0f b6 00             	movzbl (%eax),%eax
 8048535:	84 c0                	test   %al,%al
 8048537:	75 e0                	jne    8048519 <copy+0xf>
 8048539:	c9                   	leave  
 804853a:	c3                   	ret    
 804853b:	66 90                	xchg   %ax,%ax
 804853d:	66 90                	xchg   %ax,%ax
 804853f:	90                   	nop

08048540 <__libc_csu_init>:
 8048540:	55                   	push   %ebp
 8048541:	57                   	push   %edi
 8048542:	31 ff                	xor    %edi,%edi
 8048544:	56                   	push   %esi
 8048545:	53                   	push   %ebx
 8048546:	e8 25 fe ff ff       	call   8048370 <__x86.get_pc_thunk.bx>
 804854b:	81 c3 b5 1a 00 00    	add    $0x1ab5,%ebx
 8048551:	83 ec 1c             	sub    $0x1c,%esp
 8048554:	8b 6c 24 30          	mov    0x30(%esp),%ebp
 8048558:	8d b3 0c ff ff ff    	lea    -0xf4(%ebx),%esi
 804855e:	e8 69 fd ff ff       	call   80482cc <_init>
 8048563:	8d 83 08 ff ff ff    	lea    -0xf8(%ebx),%eax
 8048569:	29 c6                	sub    %eax,%esi
 804856b:	c1 fe 02             	sar    $0x2,%esi
 804856e:	85 f6                	test   %esi,%esi
 8048570:	74 27                	je     8048599 <__libc_csu_init+0x59>
 8048572:	8d b6 00 00 00 00    	lea    0x0(%esi),%esi
 8048578:	8b 44 24 38          	mov    0x38(%esp),%eax
 804857c:	89 2c 24             	mov    %ebp,(%esp)
 804857f:	89 44 24 08          	mov    %eax,0x8(%esp)
 8048583:	8b 44 24 34          	mov    0x34(%esp),%eax
 8048587:	89 44 24 04          	mov    %eax,0x4(%esp)
 804858b:	ff 94 bb 08 ff ff ff 	call   *-0xf8(%ebx,%edi,4)
 8048592:	83 c7 01             	add    $0x1,%edi
 8048595:	39 f7                	cmp    %esi,%edi
 8048597:	75 df                	jne    8048578 <__libc_csu_init+0x38>
 8048599:	83 c4 1c             	add    $0x1c,%esp
 804859c:	5b                   	pop    %ebx
 804859d:	5e                   	pop    %esi
 804859e:	5f                   	pop    %edi
 804859f:	5d                   	pop    %ebp
 80485a0:	c3                   	ret    
 80485a1:	eb 0d                	jmp    80485b0 <__libc_csu_fini>
 80485a3:	90                   	nop
 80485a4:	90                   	nop
 80485a5:	90                   	nop
 80485a6:	90                   	nop
 80485a7:	90                   	nop
 80485a8:	90                   	nop
 80485a9:	90                   	nop
 80485aa:	90                   	nop
 80485ab:	90                   	nop
 80485ac:	90                   	nop
 80485ad:	90                   	nop
 80485ae:	90                   	nop
 80485af:	90                   	nop

080485b0 <__libc_csu_fini>:
 80485b0:	f3 c3                	repz ret 

Disassembly of section .fini:

080485b4 <_fini>:
 80485b4:	53                   	push   %ebx
 80485b5:	83 ec 08             	sub    $0x8,%esp
 80485b8:	e8 b3 fd ff ff       	call   8048370 <__x86.get_pc_thunk.bx>
 80485bd:	81 c3 43 1a 00 00    	add    $0x1a43,%ebx
 80485c3:	83 c4 08             	add    $0x8,%esp
 80485c6:	5b                   	pop    %ebx
 80485c7:	c3                   	ret    
