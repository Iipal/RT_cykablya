#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "albedo.h"
#endif

t_v3sf __attribute__((__target__("avx")))
	albedo(register const t_material_sf material)
{
	return ((t_v3sf){ material[0], material[1], material[2] });
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
