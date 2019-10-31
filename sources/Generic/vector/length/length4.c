#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "length.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	length(register const t_v4sf vec)
{
	return (sqroot(length_squared(vec)));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	length(register const t_v4df vec)
{
	return (sqroot(length_squared(vec)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
