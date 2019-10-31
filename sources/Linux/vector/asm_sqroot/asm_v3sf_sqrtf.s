	.intel_syntax noprefix
	.globl	asm_v3sf_sqrtf
	.type	asm_v3sf_sqrtf, @function
asm_v3sf_sqrtf:
	.cfi_startproc
			vsqrtps		xmm0, xmm0
			ret
	.cfi_endproc
