#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "discriminant.h"
#endif

float __attribute__((__overloadable__))
	discriminant(const float a, const float b, const t_v3sf oc, const t_v3sf radius)
{
	const float		c = (length_squared(oc) - (radius * radius)).x;

	return ((b * b) - (a * c));
}

double __attribute__((__overloadable__))
	discriminant(const double a, const double b, const t_v3df oc, const t_v3df radius)
{
	const double	c = (length_squared(oc) - (radius * radius)).x;

	return ((b * b) - (a * c));
}

t_v3sf __attribute__((__overloadable__))
	discriminant(const t_v3sf a, const t_v3sf b, const t_v3sf oc, const t_v3sf radius)
{
	const t_v3sf	c = (length_squared(oc) - (radius * radius));

	return ((b * b) - (a * c));
}

t_v3df __attribute__((__overloadable__))
	discriminant(const t_v3df a, const t_v3df b, const t_v3df oc, const t_v3df radius)
{
	const t_v3df	c = (length_squared(oc) - (radius * radius));

	return ((b * b) - (a * c));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
