	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 13
	.intel_syntax noprefix
	.section	__TEXT,__literal4,4byte_literals
	.p2align	2
LCPI0_0:
	.long	1065353216
	.section	__TEXT,__text,regular,pure_instructions
	.globl	_asm_v4sf_rsqroot
	.p2align	4, 0x90
_asm_v4sf_rsqroot:
	.cfi_startproc
		push	rbp
Lcfi0:
	.cfi_def_cfa_offset 16
Lcfi1:
	.cfi_offset rbp, -16
		mov	rbp, rsp
Lcfi2:
	.cfi_def_cfa_register rbp
		vsqrtps			xmm0, xmm0
		vrcpps			xmm1, xmm0
		vbroadcastss	xmm2, dword ptr [rip + LCPI0_0]
		vfnmadd213ps	xmm0, xmm1, xmm2
		vfmadd132ps		xmm0, xmm1, xmm1
		pop	rbp
		ret
	.cfi_endproc


.subsections_via_symbols
