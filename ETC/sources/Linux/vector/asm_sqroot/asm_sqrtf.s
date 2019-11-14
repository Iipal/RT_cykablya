	.intel_syntax noprefix
	.globl	asm_sqrtf
	.type	asm_sqrtf, @function
asm_sqrtf:
	.cfi_startproc
			vsqrtss		xmm0, xmm0, xmm0
			ret
	.cfi_endproc

