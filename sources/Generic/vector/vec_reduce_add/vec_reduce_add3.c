#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vec_reduce_add.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v3sf vec)
{
	return (asm_v3sf_reduce_add(vec));
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v3df vec)
{
	return (asm_v3df_reduce_add(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
