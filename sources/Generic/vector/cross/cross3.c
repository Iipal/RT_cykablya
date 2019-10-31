#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cross.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	cross(register const t_v3sf x, register const t_v3sf y)
{
	return ((x.zxy * y - x * y.zxy).zxy);
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	cross(register const t_v3df x, register const t_v3df y)
{
	return ((x.zxy * y - x * y.zxy).zxy);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
