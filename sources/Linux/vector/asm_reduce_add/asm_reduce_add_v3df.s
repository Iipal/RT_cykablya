	.intel_syntax noprefix
	.globl	asm_reduce_add_v3df
	.type	asm_reduce_add_v3df, @function
asm_reduce_add_v3df:
	.cfi_startproc
		vhaddpd			xmm1, xmm0, xmm0
		vextractf128	xmm0, ymm0, 0x1
		vaddsd			xmm0, xmm1, xmm0
		ret
	.cfi_endproc
