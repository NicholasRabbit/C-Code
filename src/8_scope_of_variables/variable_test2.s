	.file	"variable_test2.c"
	.globl	m
	.data
	.align 4
	.type	m, @object
	.size	m, 4
m:
	.long	10
	.globl	n
	.align 4
	.type	n, @object
	.size	n, 4
n:
	.long	20
	.globl	x
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	35
	.comm	y,4,4
	.section	.rodata
	.align 4
.LC0:
	.string	"doSome: m = %d,n = %d, x = %d \n"
	.text
	.globl	doSome
	.type	doSome, @function
doSome:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$40, %esp
	movl	$66, -12(%ebp)
	movl	$77, -16(%ebp)
	movl	x, %eax
	movl	%eax, 12(%esp)
	movl	-16(%ebp), %eax
	movl	%eax, 8(%esp)
	movl	-12(%ebp), %eax
	movl	%eax, 4(%esp)
	movl	$.LC0, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	doSome, .-doSome
	.section	.rodata
.LC1:
	.string	"main: m = %d,n = %d \n"
.LC2:
	.string	"y's default value=%d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	andl	$-16, %esp
	subl	$16, %esp
	movl	n, %edx
	movl	m, %eax
	movl	%edx, 8(%esp)
	movl	%eax, 4(%esp)
	movl	$.LC1, (%esp)
	call	printf
	call	doSome
	movl	y, %eax
	movl	%eax, 4(%esp)
	movl	$.LC2, (%esp)
	call	printf
	movl	$0, %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
