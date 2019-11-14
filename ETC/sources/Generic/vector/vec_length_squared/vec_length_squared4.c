#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vec_length_squared.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_length_squared(register const t_v4sf vec)
{
	return (vec_dot(vec, vec));
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec_length_squared(register const t_v4df vec)
{
	return (vec_dot(vec, vec));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
