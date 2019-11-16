#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cone_center.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(register const t_cone_sf cone)
{
	return (cone.xyz);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
