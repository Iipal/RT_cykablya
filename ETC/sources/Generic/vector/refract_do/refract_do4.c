#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "refract_do.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_do(register const t_v4sf x,
				register const t_v4sf n,
				register const float e,
				register const float k)
{
	return (e * x - (e * dot(x, n) + sqroot(k)) * n);
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_do(register const t_v4df x,
				register const t_v4df n,
				register const double e,
				register const double k)
{
	return (e * x - (e * dot(x, n) + sqroot(k)) * n);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
