#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sqroot.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v2sf vec)
{
	register t_v4sf	res;

	res = __builtin_ia32_sqrtps((t_v4sf){ vec[0], vec[1] });
	return (t_v2sf){ res[0], res[1] };
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	sqroot(register const t_v2df vec)
{
	register t_v4df res;

	res = __builtin_ia32_sqrtpd256((t_v4df){ vec[0], vec[1] });
	return (t_v2df){ res[0], res[1] };
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
