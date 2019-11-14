	.intel_syntax noprefix
	.globl	asm_v3sf_rsqroot
	.p2align	4, 0x90
	.type	asm_v3sf_rsqroot,@function
asm_v3sf_rsqroot:
	.cfi_startproc
		vxorps	xmm1, xmm1, xmm1
		vbroadcastss	xmm2, dword ptr [rip + .LCPI0_0]
		vbroadcastss	xmm3, dword ptr [rip + .LCPI0_1]
		vblendps		xmm0, xmm0, xmm1, 8
		vrsqrtps		xmm1, xmm0
		vmulps			xmm0, xmm0, xmm1
		vfmadd213ps		xmm0, xmm1, xmm2
		vmulps			xmm1, xmm1, xmm3
		vmulps			xmm0, xmm1, xmm0
		ret

	.p2align	2               # -- Begin function asm_v3sf_rsqroot
.LCPI0_0:
	.long	3225419776              # float -3
.LCPI0_1:
	.long	3204448256              # float -0.5
	.cfi_endproc

