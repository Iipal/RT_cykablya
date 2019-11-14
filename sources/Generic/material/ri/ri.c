#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "ri.h"
#endif

float __attribute__((CONST,CLONE,ARCH))
	ri(register const t_material_sf material)
{
	return (material[5]);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
