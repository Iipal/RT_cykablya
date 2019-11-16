#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cone_height.h"
#endif

float __attribute__((CONST,CLONE,ARCH))
	height(register const t_cone_sf cone)
{
	return (cone[4]);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
