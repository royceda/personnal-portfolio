	.file	"test.c"
	.text
	.p2align 4,,15
	.globl	calculscal
	.type	calculscal, @function
calculscal:
.LFB39:
	.cfi_startproc
	imull	%edi, %edi
	leal	20(%rdi), %eax
	ret
	.cfi_endproc
.LFE39:
	.size	calculscal, .-calculscal
	.p2align 4,,15
	.globl	calcularray
	.type	calcularray, @function
calcularray:
.LFB40:
	.cfi_startproc
	xorl	%eax, %eax
	.p2align 4,,10
	.p2align 3
.L4:
	movss	(%rdi,%rax), %xmm0
	addss	(%rsi,%rax), %xmm0
	movss	%xmm0, (%rdi,%rax)
	addq	$4, %rax
	cmpq	$64, %rax
	jne	.L4
	rep ret
	.cfi_endproc
.LFE40:
	.size	calcularray, .-calcularray
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d\n"
.LC1:
	.string	"%f "
	.section	.text.startup,"ax",@progbits
	.p2align 4,,15
	.globl	main
	.type	main, @function
main:
.LFB41:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movl	$64, %edi
	pushq	%rbx
	.cfi_def_cfa_offset 24
	.cfi_offset 3, -24
	subq	$8, %rsp
	.cfi_def_cfa_offset 32
	call	malloc
	movl	$64, %edi
	movq	%rax, %rbx
	call	malloc
	xorl	%edx, %edx
	movq	%rax, %rbp
	movl	$16, %ecx
	.p2align 4,,10
	.p2align 3
.L8:
	cvtsi2ss	%edx, %xmm0
	movl	%ecx, %eax
	subl	%edx, %eax
	movss	%xmm0, 0(%rbp,%rdx,4)
	cvtsi2ss	%eax, %xmm0
	movss	%xmm0, (%rbx,%rdx,4)
	addq	$1, %rdx
	cmpq	$16, %rdx
	jne	.L8
	movb	$-67, %dl
	movl	$.LC0, %esi
	movl	$1, %edi
	xorl	%eax, %eax
	call	__printf_chk
	xorl	%edx, %edx
	.p2align 4,,10
	.p2align 3
.L10:
	movss	(%rbx,%rdx), %xmm0
	addss	0(%rbp,%rdx), %xmm0
	movss	%xmm0, (%rbx,%rdx)
	addq	$4, %rdx
	cmpq	$64, %rdx
	jne	.L10
	xorl	%ebp, %ebp
	.p2align 4,,10
	.p2align 3
.L12:
	movss	(%rbx,%rbp), %xmm0
	movl	$.LC1, %esi
	movl	$1, %edi
	movl	$1, %eax
	addq	$4, %rbp
	cvtps2pd	%xmm0, %xmm0
	call	__printf_chk
	cmpq	$64, %rbp
	jne	.L12
	addq	$8, %rsp
	.cfi_def_cfa_offset 24
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 16
	popq	%rbp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE41:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.8.2-19ubuntu1) 4.8.2"
	.section	.note.GNU-stack,"",@progbits
