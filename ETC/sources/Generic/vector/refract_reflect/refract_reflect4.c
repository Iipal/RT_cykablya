#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "refract_reflect.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_reflect(register const t_v4sf x,
					register const t_v4sf n,
					register const float e,
					register const t_v4sf reflect)
{
	register const float	k = 1.0f - e * e * (1.0f - dot(x, n) * dot(x, n));

	return (k >= 0.0f) ? e * x - (e * dot(x, n) + sqroot(k)) * n : reflect;
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_reflect(register const t_v4df x,
					register const t_v4df n,
					register const double e,
					register const t_v4df reflect)
{
	register const double	k = 1.0 - e * e * (1.0 - dot(x, n) * dot(x, n));

	return (k >= 0.0f) ? e * x - (e * dot(x, n) + sqroot(k)) * n : reflect;
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
