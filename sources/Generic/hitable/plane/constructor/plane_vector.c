#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "plane_constructor.h"
#endif

t_plane_sf __attribute__((CONST,CLONE,ARCH))
	plane(register const t_v3sf a,
			register const t_v3sf b,
			register const t_v3sf c,
			register const t_v3sf d)
{
	return (__extension__((t_plane_sf){
		a.x, a.y, a.z,
		b.x, b.y, b.z,
		c.x, c.y, c.z,
		d.x, d.y, d.z,
	}));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
