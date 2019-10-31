	.intel_syntax noprefix
	.globl	asm_v4df_sqrt
	.type	asm_v4df_sqrt, @function
asm_v4df_sqrt:
	.cfi_startproc
			vsqrtpd		ymm0, ymm0
			ret
	.cfi_endproc
