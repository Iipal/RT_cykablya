#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "albedo.h"
#endif

t_v3sf __attribute__((__target__("avx")))
	albedo(register const t_material_sf material)
{
	return (material.xyz);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
