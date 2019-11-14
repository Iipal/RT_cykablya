	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_v3df_sqrt
	.p2align	4, 0x90
_asm_v3df_sqrt:
	.cfi_startproc
		vsqrtpd		ymm0, ymm0
		ret
	.cfi_endproc

.subsections_via_symbols
