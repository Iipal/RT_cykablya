	.intel_syntax noprefix
	.globl	asm_v2df_reduce_add
	.type	asm_v2df_reduce_add, @function
asm_v2df_reduce_add:
	.cfi_startproc
		vhaddpd		xmm0, xmm0, xmm0
		ret
	.cfi_endproc
