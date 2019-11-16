#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "tetrahedron_constructor.h"
#endif

t_tetrahedron_sf __attribute__((CONST,CLONE,ARCH))
	tetrahedron(register const t_v3sf a,
				register const t_v3sf b,
				register const t_v3sf c)
{
	return (__extension__((t_tetrahedron_sf){
		a.x, a.y, a.z,
		b.x, b.y, b.z,
		c.x, c.y, c.z
	}));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
