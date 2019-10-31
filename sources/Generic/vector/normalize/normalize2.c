#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "normalize.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	normalize(register const t_v2sf x)
{
	return (x * rsqroot(vec_length_squared(x)));
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	normalize(register const t_v2df x)
{
	return (x * rsqroot(vec_length_squared(x)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
