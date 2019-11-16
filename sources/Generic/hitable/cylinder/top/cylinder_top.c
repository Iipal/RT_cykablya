#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_top.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	top(register const t_cylinder_sf cylinder)
{
	return (cylinder.hi.xyz);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
