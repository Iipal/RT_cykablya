#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cone_constructor.h"
#endif

t_cone_sf __attribute__((CONST,CLONE,ARCH))
	cone(register const t_v3sf center,
		register const float radius,
		register const float height)
{
	t_cone_sf	c;

	c.xyz = center;
	c[3] = radius;
	c[4] = height;
	return (c);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
