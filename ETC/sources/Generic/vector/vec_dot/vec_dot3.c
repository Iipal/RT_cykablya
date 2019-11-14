#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vec_dot.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_dot(register const t_v3sf x, register const t_v3sf y)
{
	return (vec_reduce_add(x * y));
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_dot(register const t_v3df x, register const t_v3df y)
{
	return (vec_reduce_add(x * y));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
