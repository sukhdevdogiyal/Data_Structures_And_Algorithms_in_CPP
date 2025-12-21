	.file	"inline.cpp"
	.section	.text$_ZNKSt5ctypeIcE8do_widenEc,"x"
	.linkonce discard
	.align 2
	.p2align 4,,15
	.globl	__ZNKSt5ctypeIcE8do_widenEc
	.def	__ZNKSt5ctypeIcE8do_widenEc;	.scl	2;	.type	32;	.endef
__ZNKSt5ctypeIcE8do_widenEc:
LFB1246:
	.cfi_startproc
	movzbl	4(%esp), %eax
	ret	$4
	.cfi_endproc
LFE1246:
	.text
	.p2align 4,,15
	.def	___tcf_0;	.scl	3;	.type	32;	.endef
___tcf_0:
LFB1923:
	.cfi_startproc
	movl	$__ZStL8__ioinit, %ecx
	jmp	__ZNSt8ios_base4InitD1Ev
	.cfi_endproc
LFE1923:
	.def	___main;	.scl	2;	.type	32;	.endef
	.section .rdata,"dr"
LC0:
	.ascii "hi\0"
LC1:
	.ascii "Sum = \0"
	.section	.text.startup,"x"
	.p2align 4,,15
	.globl	_main
	.def	_main;	.scl	2;	.type	32;	.endef
_main:
LFB1490:
	.cfi_startproc
	leal	4(%esp), %ecx
	.cfi_def_cfa 1, 0
	andl	$-16, %esp
	pushl	-4(%ecx)
	pushl	%ebp
	.cfi_escape 0x10,0x5,0x2,0x75,0
	movl	%esp, %ebp
	pushl	%esi
	pushl	%ebx
	pushl	%ecx
	.cfi_escape 0xf,0x3,0x75,0x74,0x6
	.cfi_escape 0x10,0x6,0x2,0x75,0x7c
	.cfi_escape 0x10,0x3,0x2,0x75,0x78
	movl	$10, %esi
	subl	$28, %esp
	call	___main
	jmp	L7
	.p2align 4,,10
L33:
	movsbl	39(%ebx), %eax
L6:
	movl	$__ZSt4cout, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	subl	$1, %esi
	je	L32
L7:
	movl	$2, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L8
	cmpb	$0, 28(%ebx)
	jne	L33
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L6
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	subl	$4, %esp
	movsbl	%al, %eax
	jmp	L6
	.p2align 4,,10
L32:
	movl	$10, %esi
	jmp	L11
	.p2align 4,,10
L35:
	movsbl	39(%ebx), %eax
L10:
	movl	$__ZSt4cout, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	subl	$1, %esi
	je	L34
L11:
	movl	$2, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L8
	cmpb	$0, 28(%ebx)
	jne	L35
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L10
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	subl	$4, %esp
	movsbl	%al, %eax
	jmp	L10
	.p2align 4,,10
L34:
	movl	$10, %esi
	jmp	L14
	.p2align 4,,10
L37:
	movsbl	39(%ebx), %eax
L13:
	movl	$__ZSt4cout, %ecx
	movl	%eax, (%esp)
	call	__ZNSo3putEc
	subl	$4, %esp
	movl	%eax, %ecx
	call	__ZNSo5flushEv
	subl	$1, %esi
	je	L36
L14:
	movl	$2, 8(%esp)
	movl	$LC0, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	__ZSt4cout, %eax
	movl	-12(%eax), %eax
	movl	__ZSt4cout+124(%eax), %ebx
	testl	%ebx, %ebx
	je	L8
	cmpb	$0, 28(%ebx)
	jne	L37
	movl	%ebx, %ecx
	call	__ZNKSt5ctypeIcE13_M_widen_initEv
	movl	(%ebx), %eax
	movl	24(%eax), %edx
	movl	$10, %eax
	cmpl	$__ZNKSt5ctypeIcE8do_widenEc, %edx
	je	L13
	movl	$10, (%esp)
	movl	%ebx, %ecx
	call	*%edx
	subl	$4, %esp
	movsbl	%al, %eax
	jmp	L13
	.p2align 4,,10
L36:
	movl	$6, 8(%esp)
	movl	$LC1, 4(%esp)
	movl	$__ZSt4cout, (%esp)
	call	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i
	movl	$__ZSt4cout, %ecx
	movl	$7, (%esp)
	call	__ZNSolsEi
	subl	$4, %esp
	leal	-12(%ebp), %esp
	xorl	%eax, %eax
	popl	%ecx
	.cfi_remember_state
	.cfi_restore 1
	.cfi_def_cfa 1, 0
	popl	%ebx
	.cfi_restore 3
	popl	%esi
	.cfi_restore 6
	popl	%ebp
	.cfi_restore 5
	leal	-4(%ecx), %esp
	.cfi_def_cfa 4, 4
	ret
L8:
	.cfi_restore_state
	call	__ZSt16__throw_bad_castv
	.cfi_endproc
LFE1490:
	.p2align 4,,15
	.def	__GLOBAL__sub_I_main;	.scl	3;	.type	32;	.endef
__GLOBAL__sub_I_main:
LFB1924:
	.cfi_startproc
	subl	$28, %esp
	.cfi_def_cfa_offset 32
	movl	$__ZStL8__ioinit, %ecx
	call	__ZNSt8ios_base4InitC1Ev
	movl	$___tcf_0, (%esp)
	call	_atexit
	addl	$28, %esp
	.cfi_def_cfa_offset 4
	ret
	.cfi_endproc
LFE1924:
	.section	.ctors,"w"
	.align 4
	.long	__GLOBAL__sub_I_main
.lcomm __ZStL8__ioinit,1,1
	.ident	"GCC: (MinGW.org GCC-6.3.0-1) 6.3.0"
	.def	__ZNSt8ios_base4InitD1Ev;	.scl	2;	.type	32;	.endef
	.def	__ZNSo3putEc;	.scl	2;	.type	32;	.endef
	.def	__ZNSo5flushEv;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__ostream_insertIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_PKS3_i;	.scl	2;	.type	32;	.endef
	.def	__ZNKSt5ctypeIcE13_M_widen_initEv;	.scl	2;	.type	32;	.endef
	.def	__ZNSolsEi;	.scl	2;	.type	32;	.endef
	.def	__ZSt16__throw_bad_castv;	.scl	2;	.type	32;	.endef
	.def	__ZNSt8ios_base4InitC1Ev;	.scl	2;	.type	32;	.endef
	.def	_atexit;	.scl	2;	.type	32;	.endef
