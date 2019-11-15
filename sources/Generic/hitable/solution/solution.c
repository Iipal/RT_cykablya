#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "solution.h"
#endif

float __attribute__((CONST,CLONE,ARCH))
	solution(register const float a,
			register const float b,
			register const float c)
{
	const float		d = b * b - 4.0f * (a * c);
	const float		x_0 = (-b - sqroot(d)) / (2.0f * a);
	const float		x_1 = (-b + sqroot(d)) / (2.0f * a);

	return ((x_0 > x_1) ? x_1 : x_0);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
