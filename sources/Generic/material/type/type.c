#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "type.h"
#endif

enum e_material __attribute__((__target__("avx,avx2")))
	type(register const t_material_sf material)
{
	return ((enum e_material)(((t_material_si)material)[4]));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
