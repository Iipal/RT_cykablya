	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_reduce_add_v3df
	.p2align	4, 0x90
_asm_reduce_add_v3df:
	.cfi_startproc
		vhaddpd			xmm1, xmm0, xmm0
		vextractf128	xmm0, ymm0, 0x1
		vaddsd			xmm0, xmm1, xmm0
		ret
	.cfi_endproc

.subsections_via_symbols
