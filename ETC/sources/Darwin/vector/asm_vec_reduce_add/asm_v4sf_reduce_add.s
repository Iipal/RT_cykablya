	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_v4sf_reduce_add
	.p2align	4, 0x90
_asm_v4sf_reduce_add:
	.cfi_startproc
		vpermilpd	xmm1, xmm0, 3	;# xmm1 = xmm0[1,1]
		vmovddup	xmm0, xmm0		;# xmm0 = xmm0[0,0]
		vaddps		xmm0, xmm1, xmm0
		vhaddps		xmm0, xmm0, xmm0
		ret
	.cfi_endproc

.subsections_via_symbols
