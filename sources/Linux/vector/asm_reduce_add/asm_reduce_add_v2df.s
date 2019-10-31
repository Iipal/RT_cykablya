	.intel_syntax noprefix
	.globl	asm_reduce_add_v2df
	.type	asm_reduce_add_v2df, @function
asm_reduce_add_v2df:
	.cfi_startproc
		vhaddpd		xmm0, xmm0, xmm0
		ret
	.cfi_endproc
