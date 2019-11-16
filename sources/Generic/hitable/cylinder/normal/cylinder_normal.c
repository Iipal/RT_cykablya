#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_normal.h"
#endif

static t_v3sf __attribute__((CONST,CLONE,ARCH))
	axis(register const t_cylinder_sf cylinder)
{
	return (normalize(top(cylinder) - center(cylinder)));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_cylinder_sf cyl,
			register const t_v3sf point)
{
	(void)point;
	return normalize(vec(point.x - center(cyl).x,
						0.0f,
						point.z - center(cyl).z));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_cylinder_sf cyl,
			register const t_ray_sf ray,
			register const float t)
{
	float	m;

	m = dot(direction(ray), axis(cyl)) * t
	+ dot(origin(ray) - direction(ray), axis(cyl));
    return (normalize(point_at_parameter(ray, t)
		    				- center(cyl)
		    				- axis(cyl) * m));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
