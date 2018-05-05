	.file	"Project6.c"
	.text
.globl main
	.type	main, @function
main:
.LFB2:
	pushq	%rbp
.LCFI0:
	movq	%rsp, %rbp
.LCFI1:
	subq	$64, %rsp
.LCFI2:
	leaq	-48(%rbp), %rdi
	call	getFileName
	leaq	-48(%rbp), %rdi
	call	howManyLines
	addl	$1, %eax
	cltq
	movq	%rax, %rdi
	salq	$7, %rdi
	call	malloc
	movq	%rax, -8(%rbp)
	leaq	-52(%rbp), %rdx
	movq	-8(%rbp), %rsi
	leaq	-48(%rbp), %rdi
	call	readFileIntoArray
	movl	-52(%rbp), %esi
	movq	-8(%rbp), %rdi
	call	getStats
	movl	$0, %eax
	leave
	ret
.LFE2:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC0:
	.string	"%s had the highest grade on project %d, a %d\n"
	.text
.globl getStats
	.type	getStats, @function
getStats:
.LFB3:
	pushq	%rbp
.LCFI3:
	movq	%rsp, %rbp
.LCFI4:
	subq	$32, %rsp
.LCFI5:
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movl	$7, -16(%rbp)
	movl	$0, -8(%rbp)
	jmp	.L4
.L11:
	movl	$0, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	salq	$7, %rax
	movq	%rax, %rdx
	addq	-24(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	$24, %rax
	movl	4(%rdx,%rax,4), %eax
	movl	%eax, -12(%rbp)
	movl	$0, -4(%rbp)
	jmp	.L5
.L7:
	movl	-4(%rbp), %eax
	cltq
	salq	$7, %rax
	movq	%rax, %rdx
	addq	-24(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	$24, %rax
	movl	4(%rdx,%rax,4), %eax
	cmpl	-12(%rbp), %eax
	jle	.L6
	movl	-4(%rbp), %eax
	cltq
	salq	$7, %rax
	movq	%rax, %rdx
	addq	-24(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	$24, %rax
	movl	4(%rdx,%rax,4), %eax
	movl	%eax, -12(%rbp)
.L6:
	addl	$1, -4(%rbp)
.L5:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L7
	movl	$0, -4(%rbp)
	jmp	.L8
.L10:
	movl	-4(%rbp), %eax
	cltq
	salq	$7, %rax
	movq	%rax, %rdx
	addq	-24(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	$24, %rax
	movl	4(%rdx,%rax,4), %eax
	cmpl	-12(%rbp), %eax
	jne	.L9
	movl	-4(%rbp), %eax
	cltq
	salq	$7, %rax
	movq	%rax, %rdx
	addq	-24(%rbp), %rdx
	movl	-8(%rbp), %eax
	cltq
	addq	$24, %rax
	movl	4(%rdx,%rax,4), %ecx
	movl	-8(%rbp), %eax
	leal	1(%rax), %edx
	movl	-4(%rbp), %eax
	cltq
	salq	$7, %rax
	addq	-24(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
.L9:
	addl	$1, -4(%rbp)
.L8:
	movl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L10
	movl	$10, %edi
	call	putchar
	addl	$1, -8(%rbp)
.L4:
	movl	-8(%rbp), %eax
	cmpl	-16(%rbp), %eax
	jl	.L11
	leave
	ret
.LFE3:
	.size	getStats, .-getStats
	.section	.rodata
.LC1:
	.string	"r"
.LC2:
	.string	"%s"
.LC3:
	.string	" "
.LC4:
	.string	"%d"
.LC5:
	.string	"%c"
	.text
.globl readFileIntoArray
	.type	readFileIntoArray, @function
readFileIntoArray:
.LFB4:
	pushq	%rbp
.LCFI6:
	movq	%rsp, %rbp
.LCFI7:
	pushq	%rbx
.LCFI8:
	subq	$248, %rsp
.LCFI9:
	movq	%rdi, -232(%rbp)
	movq	%rsi, -240(%rbp)
	movq	%rdx, -248(%rbp)
	movl	$0, -28(%rbp)
	movq	-232(%rbp), %rdi
	movl	$.LC1, %esi
	call	fopen
	movq	%rax, -24(%rbp)
.L17:
	leaq	-80(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC2, %esi
	movl	$0, %eax
	call	fscanf
	leaq	-80(%rbp), %rdi
	call	strlen
	movl	%eax, -32(%rbp)
	leaq	-80(%rbp), %rbx
	leaq	-80(%rbp), %rdi
	call	strlen
	leaq	(%rbx,%rax), %rax
	movq	%rax, %rdi
	movl	$2, %edx
	movl	$.LC3, %esi
	call	memcpy
	movl	-32(%rbp), %eax
	subl	$1, %eax
	cltq
	movzbl	-80(%rbp,%rax), %eax
	cmpb	$44, %al
	je	.L14
	leaq	-128(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC2, %esi
	movl	$0, %eax
	call	fscanf
	leaq	-128(%rbp), %rsi
	leaq	-80(%rbp), %rdi
	call	strcat
	leaq	-80(%rbp), %rdi
	movl	$.LC3, %esi
	call	strcat
.L14:
	leaq	-176(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC2, %esi
	movl	$0, %eax
	call	fscanf
	leaq	-176(%rbp), %rsi
	leaq	-80(%rbp), %rdi
	call	strcat
	movl	-28(%rbp), %eax
	cltq
	salq	$7, %rax
	addq	-240(%rbp), %rax
	movq	%rax, %rdi
	leaq	-80(%rbp), %rsi
	call	strcpy
	leaq	-192(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC2, %esi
	movl	$0, %eax
	call	fscanf
	leaq	-208(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC2, %esi
	movl	$0, %eax
	call	fscanf
	leaq	-40(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC4, %esi
	movl	$0, %eax
	call	fscanf
	movl	$0, -36(%rbp)
	jmp	.L15
.L16:
	movl	-28(%rbp), %eax
	cltq
	salq	$7, %rax
	addq	-240(%rbp), %rax
	leaq	100(%rax), %rdx
	movl	-36(%rbp), %eax
	cltq
	salq	$2, %rax
	addq	%rax, %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC4, %esi
	movl	$0, %eax
	call	fscanf
	addl	$1, -36(%rbp)
.L15:
	cmpl	$6, -36(%rbp)
	jle	.L16
	addl	$1, -28(%rbp)
	leaq	-209(%rbp), %rdx
	movq	-24(%rbp), %rdi
	movl	$.LC5, %esi
	movl	$0, %eax
	call	fscanf
	cmpl	$-1, %eax
	jne	.L17
	movq	-24(%rbp), %rdi
	call	fclose
	movq	-248(%rbp), %rdx
	movl	-28(%rbp), %eax
	movl	%eax, (%rdx)
	addq	$248, %rsp
	popq	%rbx
	leave
	ret
.LFE4:
	.size	readFileIntoArray, .-readFileIntoArray
	.section	.rodata
	.align 8
.LC6:
	.string	"Where are the grades? Enter a filename that ends with .xls "
	.text
.globl getFileName
	.type	getFileName, @function
getFileName:
.LFB5:
	pushq	%rbp
.LCFI10:
	movq	%rsp, %rbp
.LCFI11:
	subq	$32, %rsp
.LCFI12:
	movq	%rdi, -24(%rbp)
.L20:
	movl	$.LC6, %edi
	movl	$0, %eax
	call	printf
	movq	stdout(%rip), %rdi
	call	fflush
	movq	-24(%rbp), %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	scanf
	movq	-24(%rbp), %rdi
	call	strlen
	movl	%eax, -4(%rbp)
	movl	-4(%rbp), %eax
	cltq
	subq	$1, %rax
	addq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$115, %al
	jne	.L20
	movl	-4(%rbp), %eax
	cltq
	subq	$2, %rax
	addq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$108, %al
	jne	.L20
	movl	-4(%rbp), %eax
	cltq
	subq	$3, %rax
	addq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$120, %al
	jne	.L20
	movl	-4(%rbp), %eax
	cltq
	subq	$4, %rax
	addq	-24(%rbp), %rax
	movzbl	(%rax), %eax
	cmpb	$46, %al
	jne	.L20
	leave
	ret
.LFE5:
	.size	getFileName, .-getFileName
.globl howManyLines
	.type	howManyLines, @function
howManyLines:
.LFB6:
	pushq	%rbp
.LCFI13:
	movq	%rsp, %rbp
.LCFI14:
	subq	$48, %rsp
.LCFI15:
	movq	%rdi, -40(%rbp)
	movl	$0, -8(%rbp)
	movl	$0, -4(%rbp)
	movq	-40(%rbp), %rdi
	movl	$.LC1, %esi
	call	fopen
	movq	%rax, -16(%rbp)
	jmp	.L23
.L25:
	movzbl	-17(%rbp), %eax
	cmpb	$10, %al
	jne	.L24
	cmpl	$0, -4(%rbp)
	jne	.L24
	addl	$1, -8(%rbp)
	movl	$1, -4(%rbp)
	jmp	.L23
.L24:
	movzbl	-17(%rbp), %eax
	cmpb	$10, %al
	je	.L23
	movl	$0, -4(%rbp)
.L23:
	leaq	-17(%rbp), %rdx
	movq	-16(%rbp), %rdi
	movl	$.LC5, %esi
	movl	$0, %eax
	call	fscanf
	cmpl	$-1, %eax
	jne	.L25
	movq	-16(%rbp), %rdi
	call	fclose
	movl	-8(%rbp), %eax
	leave
	ret
.LFE6:
	.size	howManyLines, .-howManyLines
	.section	.eh_frame,"a",@progbits
.Lframe1:
	.long	.LECIE1-.LSCIE1
.LSCIE1:
	.long	0x0
	.byte	0x1
	.string	"zR"
	.uleb128 0x1
	.sleb128 -8
	.byte	0x10
	.uleb128 0x1
	.byte	0x3
	.byte	0xc
	.uleb128 0x7
	.uleb128 0x8
	.byte	0x90
	.uleb128 0x1
	.align 8
.LECIE1:
.LSFDE1:
	.long	.LEFDE1-.LASFDE1
.LASFDE1:
	.long	.LASFDE1-.Lframe1
	.long	.LFB2
	.long	.LFE2-.LFB2
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI0-.LFB2
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI1-.LCFI0
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE1:
.LSFDE3:
	.long	.LEFDE3-.LASFDE3
.LASFDE3:
	.long	.LASFDE3-.Lframe1
	.long	.LFB3
	.long	.LFE3-.LFB3
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI3-.LFB3
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI4-.LCFI3
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE3:
.LSFDE5:
	.long	.LEFDE5-.LASFDE5
.LASFDE5:
	.long	.LASFDE5-.Lframe1
	.long	.LFB4
	.long	.LFE4-.LFB4
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI6-.LFB4
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI7-.LCFI6
	.byte	0xd
	.uleb128 0x6
	.byte	0x4
	.long	.LCFI9-.LCFI7
	.byte	0x83
	.uleb128 0x3
	.align 8
.LEFDE5:
.LSFDE7:
	.long	.LEFDE7-.LASFDE7
.LASFDE7:
	.long	.LASFDE7-.Lframe1
	.long	.LFB5
	.long	.LFE5-.LFB5
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI10-.LFB5
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI11-.LCFI10
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE7:
.LSFDE9:
	.long	.LEFDE9-.LASFDE9
.LASFDE9:
	.long	.LASFDE9-.Lframe1
	.long	.LFB6
	.long	.LFE6-.LFB6
	.uleb128 0x0
	.byte	0x4
	.long	.LCFI13-.LFB6
	.byte	0xe
	.uleb128 0x10
	.byte	0x86
	.uleb128 0x2
	.byte	0x4
	.long	.LCFI14-.LCFI13
	.byte	0xd
	.uleb128 0x6
	.align 8
.LEFDE9:
	.ident	"GCC: (Debian 4.3.2-1) 4.3.2"
	.section	.note.GNU-stack,"",@progbits
