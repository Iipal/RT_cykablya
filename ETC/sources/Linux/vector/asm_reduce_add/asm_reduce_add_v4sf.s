	.intel_syntax noprefix
	.globl	asm_reduce_add_v4sf
	.p2align	4, 0x90
	.type	asm_reduce_add_v4sf, @function
asm_reduce_add_v4sf:
	.cfi_startproc
		vpermilpd	xmm1, xmm0, 1		;# xmm1 = xmm0[1,0]
		vaddps		xmm0, xmm1, xmm0
		vmovshdup	xmm1, xmm0			;# xmm1 = xmm0[1,1,3,3]
		vaddps		xmm0, xmm0, xmm1
		ret
	.cfi_endproc
