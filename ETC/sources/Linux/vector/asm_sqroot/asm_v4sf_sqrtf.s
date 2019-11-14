	.intel_syntax noprefix
	.globl	asm_v4sf_sqrtf
	.type	asm_v4sf_sqrtf, @function
asm_v4sf_sqrtf:
	.cfi_startproc
			vsqrtps		xmm0, xmm0
			ret
	.cfi_endproc
