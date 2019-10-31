	.intel_syntax noprefix
	.globl	asm_reduce_add_v2sf
	.type	asm_reduce_add_v2sf, @function
asm_reduce_add_v2sf:
	.cfi_startproc
		vmovshdup	xmm1, xmm0      ;# xmm1 = xmm0[1,1,3,3]
		vaddss		xmm0, xmm0, xmm1
		ret
	.cfi_endproc
