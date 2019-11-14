#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "refract_cond.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_cond(register const t_v3sf x,
				register const t_v3sf n,
				register const float e)
{
	return (1.0f - e * e * (1.0f - dot(x, n) * dot(x, n)));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_cond(register const t_v3df x,
				register const t_v3df n,
				register const double e)
{
	return (1.0 - e * e * (1.0 - dot(x, n) * dot(x, n)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
