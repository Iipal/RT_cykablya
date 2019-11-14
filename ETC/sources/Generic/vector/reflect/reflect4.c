#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "reflect.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reflect(register const t_v4sf x, register const t_v4sf n)
{
	return (x - 2.0f * vec_dot(x, n) * n);
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reflect(register const t_v4df x, register const t_v4df n)
{
	return (x - 2.0 * vec_dot(x, n) * n);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
