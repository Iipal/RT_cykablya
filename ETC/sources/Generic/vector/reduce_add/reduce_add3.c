#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "reduce_add.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reduce_add(register const t_v3sf vec)
{
	return (asm_reduce_add_v3sf(vec));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reduce_add(register const t_v3df vec)
{
	return (asm_reduce_add_v3df(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
