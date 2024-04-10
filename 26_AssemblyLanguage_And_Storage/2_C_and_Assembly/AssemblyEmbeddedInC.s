	.file	"AssemblyEmbeddedInC.c"
	.section	.rodata
.LC0:
	.string	"c = %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
#APP
# 15 "AssemblyEmbeddedInC.c" 1
	movl $1, %eax
	movl $5, %ebx
	int $0x80
# 0 "" 2
#NO_APP
	movl	$10, -4(%rbp)
	movl	-4(%rbp), %edx
#APP
# 25 "AssemblyEmbeddedInC.c" 1
	movl %edx, %eax
	movl %eax, %edx
# 0 "" 2
#NO_APP
	movl	%edx, -8(%rbp)
	movl	$12, -12(%rbp)
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 4.8.5 20150623 (Red Hat 4.8.5-44)"
	.section	.note.GNU-stack,"",@progbits
