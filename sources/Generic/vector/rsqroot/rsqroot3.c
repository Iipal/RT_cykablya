#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "rsqroot.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v3sf x)
{
	return (asm_v3sf_rsqroot(x));
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v3df x)
{
	const t_v4df	one = (const t_v4df){ 1.0, 1.0, 1.0, 1.0 };
	const t_v4df	t = (const t_v4df){ x.x, x.y, x.z };
	const t_v4df	result = one / __builtin_ia32_sqrtpd256(t);

	return (*(const t_v3df*)&result);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
