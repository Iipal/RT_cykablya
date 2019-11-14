#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vec_dot.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_dot(register const t_v4sf x, register const t_v4sf y)
{
	return (vec_reduce_add(x * y));
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_dot(register const t_v4df x, register const t_v4df y)
{
	return (vec_reduce_add(x * y));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
