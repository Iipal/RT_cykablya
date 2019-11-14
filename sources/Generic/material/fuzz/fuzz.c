#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "fuzz.h"
#endif

float __attribute__((CONST,SMALL_STACK,ARCH))
	fuzz(register const t_material_sf material)
{
	return (material[5]);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
