	.intel_syntax noprefix
	.globl	asm_v3df_reduce_add
	.type	asm_v3df_reduce_add, @function
asm_v3df_reduce_add:
	.cfi_startproc
		vpermpd		ymm1, ymm0, 68
		vpermpd		ymm0, ymm0, 238
		vaddpd		ymm0, ymm1, ymm0
		vxorpd		xmm1, xmm1, xmm1
		vhaddpd		ymm0, ymm0, ymm0
		vblendpd	ymm0, ymm0, ymm1, 8
		ret
	.cfi_endproc
