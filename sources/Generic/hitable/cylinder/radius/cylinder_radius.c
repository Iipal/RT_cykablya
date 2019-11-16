#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_radius.h"
#endif

float __attribute__((CONST,CLONE,ARCH))
	radius(register const t_cylinder_sf cylinder)
{
	return (cylinder.lo.w);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
