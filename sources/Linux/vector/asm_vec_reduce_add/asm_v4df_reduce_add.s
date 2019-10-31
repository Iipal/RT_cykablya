	.intel_syntax noprefix
	.globl	asm_v4df_reduce_add
	.type	asm_v4df_reduce_add, @function
asm_v4df_reduce_add:
	.cfi_startproc
		vperm2f128		ymm1, ymm0, ymm0, 2
		vperm2f128		ymm0, ymm0, ymm0, 19
		vaddpd			ymm0, ymm1, ymm0
		vhaddpd			ymm0, ymm0, ymm0
		ret
	.cfi_endproc
