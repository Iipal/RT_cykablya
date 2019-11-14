#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vec_reduce_add.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v4sf vec)
{
	return (asm_v4sf_reduce_add(vec));
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_reduce_add(register const t_v4df vec)
{
	return (asm_v4df_reduce_add(vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
