	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_v4df_reduce_add
	.p2align	4, 0x90
_asm_v4df_reduce_add:
	.cfi_startproc
		vperm2f128		ymm1, ymm0, ymm0, 2
		vperm2f128		ymm0, ymm0, ymm0, 19
		vaddpd			ymm0, ymm1, ymm0
		vhaddpd			ymm0, ymm0, ymm0
		ret
	.cfi_endproc

.subsections_via_symbols
