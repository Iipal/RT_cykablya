#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "length_squared.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	length_squared(register const t_v2sf vec)
{
	return (dot(vec, vec));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	length_squared(register const t_v2df vec)
{
	return (dot(vec, vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
