#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vector_constructor.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec(register const float e_0,
		register const float e_1,
		register const float e_2,
		register const float e_3)
{
	return ((const t_v4sf){ e_0, e_1, e_2, e_3 });
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec(register const double e_0,
		register const double e_1,
		register const double e_2,
		register const double e_3)
{
	return ((const t_v4df){ e_0, e_1, e_2, e_3 });
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
