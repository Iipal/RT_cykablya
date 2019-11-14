#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "rsqroot.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v2sf x)
{
	return (asm_v2sf_rsqroot(x));
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	rsqroot(register const t_v2df x)
{
	return ((const t_v2df){ 1.0, 1.0 } / __builtin_ia32_sqrtpd(x));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
