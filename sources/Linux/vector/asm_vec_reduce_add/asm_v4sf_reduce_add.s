	.intel_syntax noprefix
	.globl	asm_v4sf_reduce_add
	.type	asm_v4sf_reduce_add, @function
asm_v4sf_reduce_add:
	.cfi_startproc
		vpermilpd	xmm1, xmm0, 3	;# xmm1 = xmm0[1,1]
		vmovddup	xmm0, xmm0		;# xmm0 = xmm0[0,0]
		vaddps		xmm0, xmm1, xmm0
		vhaddps		xmm0, xmm0, xmm0
		ret
	.cfi_endproc
