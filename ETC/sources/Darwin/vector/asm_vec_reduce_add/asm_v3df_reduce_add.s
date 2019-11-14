	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_v3df_reduce_add
	.p2align	4, 0x90
_asm_v3df_reduce_add:
	.cfi_startproc
		vpermpd		ymm1, ymm0, 68
		vpermpd		ymm0, ymm0, 238
		vaddpd		ymm0, ymm1, ymm0
		vxorpd		xmm1, xmm1, xmm1
		vhaddpd		ymm0, ymm0, ymm0
		vblendpd	ymm0, ymm0, ymm1, 8
		ret
	.cfi_endproc

.subsections_via_symbols
