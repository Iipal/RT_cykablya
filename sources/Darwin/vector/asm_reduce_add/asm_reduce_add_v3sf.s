	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.globl	_asm_reduce_add_v3sf
	.p2align	4, 0x90
_asm_reduce_add_v3sf:
	.cfi_startproc
		vmovshdup	xmm1, xmm0			# xmm1 = xmm0[1,1,3,3]
		vaddss		xmm1, xmm0, xmm1
		vpermilpd	xmm0, xmm0, 1		# xmm0 = xmm0[1,0]
		vaddss		xmm0, xmm1, xmm0
		ret
	.cfi_endproc

.subsections_via_symbols
