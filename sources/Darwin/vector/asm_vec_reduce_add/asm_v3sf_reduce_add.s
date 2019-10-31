	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_v3sf_reduce_add
	.p2align	4, 0x90
_asm_v3sf_reduce_add:
	.cfi_startproc
		vbroadcastss	xmm1, xmm0
		vpermilps		xmm2, xmm0, 213
		vpermilps		xmm0, xmm0, 234
		vaddps			xmm1, xmm1, xmm2
		vaddps			xmm0, xmm1, xmm0
		ret
	.cfi_endproc

.subsections_via_symbols
