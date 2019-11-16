#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_constructor.h"
#endif

t_cylinder_sf __attribute__((CONST,CLONE,ARCH))
	cylinder(register const t_v3sf center,
			register const float radius,
			register const float height)
{
	t_cylinder_sf	c;

	c.xyz = center;
	c[3] = radius;
	c[4] = height;
	return (c);
}

t_cylinder_sf __attribute__((CONST,CLONE,ARCH))
	cylinder(register const t_v3sf center,
			register const t_v3sf top,
			register const float radius)
{
	t_cylinder_sf	c;

	c.lo.xyz = center;
	c.hi.xyz = top;
	c.lo.w = radius;
	return (c);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
