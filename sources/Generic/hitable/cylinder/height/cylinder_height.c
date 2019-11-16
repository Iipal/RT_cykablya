#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_height.h"
#endif

float __attribute__((CONST,CLONE,ARCH))
	height(register const t_cylinder_sf cylinder)
{
	return (length(top(cylinder) - center(cylinder)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
