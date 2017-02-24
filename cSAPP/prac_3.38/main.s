	.file	"main.c"
	.text
	.globl	fix_set_diag
	.type	fix_set_diag, @function
fix_set_diag:
.LFB39:
	.cfi_startproc
	movl	$0, %eax
.L3:
	movl	%esi, (%rdi,%rax)
	addq	$28, %rax
	cmpq	$168, %rax
	jne	.L3
	rep ret
	.cfi_endproc
.LFE39:
	.size	fix_set_diag, .-fix_set_diag
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
