#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vec_reduce_add.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v2sf vec)
{
	return (asm_v2sf_reduce_add(vec));
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v2df vec)
{
	return (asm_v2df_reduce_add(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
