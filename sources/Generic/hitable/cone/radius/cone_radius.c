#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cone_radius.h"
#endif

# include "cone.h"

float __attribute__((CONST,CLONE,ARCH))
	radius(register const t_cone_sf cone)
{
	return (cone[3]);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
