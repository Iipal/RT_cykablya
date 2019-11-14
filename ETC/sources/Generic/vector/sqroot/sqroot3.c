#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sqroot.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v3sf vec)
{
	return (asm_v3sf_sqrtf(vec));
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v3df vec)
{
	return (asm_v3df_sqrt(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
