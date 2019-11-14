	.intel_syntax noprefix
	.globl	asm_v3df_sqrt
	.type	asm_v3df_sqrt, @function
asm_v3df_sqrt:
	.cfi_startproc
			vsqrtpd		ymm0, ymm0
			ret
	.cfi_endproc
