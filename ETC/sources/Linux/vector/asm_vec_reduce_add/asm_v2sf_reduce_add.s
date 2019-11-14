	.intel_syntax noprefix
	.globl	asm_v2sf_reduce_add
	.type	asm_v2sf_reduce_add, @function
asm_v2sf_reduce_add:
	.cfi_startproc
		vmovshdup		xmm1, xmm0			;# xmm1 = xmm0[1,1,3,3]
		vaddss			xmm0, xmm0, xmm1
		vbroadcastss	xmm0, xmm0
		ret
	.cfi_endproc
