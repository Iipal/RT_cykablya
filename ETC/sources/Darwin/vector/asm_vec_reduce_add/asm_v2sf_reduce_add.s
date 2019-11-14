	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_v2sf_reduce_add
	.p2align	4, 0x90
_asm_v2sf_reduce_add:
	.cfi_startproc
		vmovshdup		xmm1, xmm0			;# xmm1 = xmm0[1,1,3,3]
		vaddss			xmm0, xmm0, xmm1
		vbroadcastss	xmm0, xmm0
		ret
	.cfi_endproc

.subsections_via_symbols
