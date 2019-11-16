#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_center.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(register const t_cylinder_sf cylinder)
{
	return (cylinder.lo.xyz);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
