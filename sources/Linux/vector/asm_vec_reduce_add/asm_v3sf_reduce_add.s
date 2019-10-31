	.intel_syntax noprefix
	.globl	asm_v3sf_reduce_add
	.type	asm_v3sf_reduce_add, @function
asm_v3sf_reduce_add:
	.cfi_startproc
		vbroadcastss	xmm1, xmm0
		vpermilps		xmm2, xmm0, 213
		vpermilps		xmm0, xmm0, 234
		vaddps			xmm1, xmm1, xmm2
		vaddps			xmm0, xmm1, xmm0
		ret
	.cfi_endproc
