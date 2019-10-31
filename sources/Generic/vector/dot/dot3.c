#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "dot.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	dot(register const t_v3sf x, register const t_v3sf y)
{
	return (reduce_add(x * y));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	dot(register const t_v3df x, register const t_v3df y)
{
	return (reduce_add(x * y));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
