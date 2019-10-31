#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "normalize.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	normalize(register const t_v4sf x)
{
	return (x * rsqroot(vec_length_squared(x)));
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	normalize(register const t_v4df x)
{
	return (x * rsqroot(vec_length_squared(x)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
