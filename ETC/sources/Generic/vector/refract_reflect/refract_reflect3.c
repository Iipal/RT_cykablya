#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "refract_reflect.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_reflect(register const t_v3sf x,
					register const t_v3sf n,
					register const float e,
					register const t_v3sf reflect)
{
	register const float	k = 1.0f - e * e * (1.0f - dot(x, n) * dot(x, n));

	return (k >= 0.0f) ? e * x - (e * dot(x, n) + sqroot(k)) * n : reflect;
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_reflect(register const t_v3df x,
					register const t_v3df n,
					register const double e,
					register const t_v3df reflect)
{
	register const double	k = 1.0 - e * e * (1.0 - dot(x, n) * dot(x, n));

	return (k >= 0.0f) ? e * x - (e * dot(x, n) + sqroot(k)) * n : reflect;
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
