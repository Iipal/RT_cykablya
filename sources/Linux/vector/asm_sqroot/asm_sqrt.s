	.intel_syntax noprefix
	.globl	asm_sqrt
	.type	asm_sqrt, @function
asm_sqrt:
	.cfi_startproc
			vsqrtsd		xmm0, xmm0, xmm0
			ret
	.cfi_endproc
