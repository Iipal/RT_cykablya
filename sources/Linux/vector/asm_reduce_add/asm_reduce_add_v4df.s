	.intel_syntax noprefix
	.globl	asm_reduce_add_v4df
	.p2align	4, 0x90
	.type	asm_reduce_add_v4df, @function
asm_reduce_add_v4df:
	.cfi_startproc
		vperm2f128	ymm1, ymm0, ymm0, 2
		vperm2f128	ymm0, ymm0, ymm0, 19
		vaddpd		ymm0, ymm1, ymm0
		vhaddpd		ymm0, ymm0, ymm0
		ret
	.cfi_endproc
