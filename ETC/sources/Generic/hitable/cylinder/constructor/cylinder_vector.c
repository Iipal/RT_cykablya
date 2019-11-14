#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_constructor.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(register const t_cylinder_sf cylinder)
{
	return (cylinder.xyz);
}

float __attribute__((CONST,CLONE,ARCH))
	radius(register const t_cylinder_sf cylinder)
{
	return (cylinder[3]);
}

float __attribute__((CONST,CLONE,ARCH))
	height(register const t_cylinder_sf cylinder)
{
	return (cylinder[4]);
}

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

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_cylinder_sf cyl,
			register const t_v3sf point)
{
    return normalize(vec(point.x - center(cyl).x,
						0.0f,
    					point.z - center(cyl).z));
}

static float __attribute__((CONST,CLONE,ARCH))
	solution(register const float a,
			register const float b,
			register const float c)
{
	const float		d = b * b - 4.0f * (a * c);
	const float		x_0 = (-b - sqroot(d)) / (2.0f * a);
	const float		x_1 = (-b + sqroot(d)) / (2.0f * a);

	return ((x_0 > x_1) ? x_1 : x_0);
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_cylinder_sf cyl,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max,
		register const t_record_sf current_record)
{
	float	a = (direction(ray).x * direction(ray).x) + (direction(ray).z * direction(ray).z);
	float	b = 2*(direction(ray).x*(origin(ray).x-center(cyl).x) + direction(ray).z*(origin(ray).z-center(cyl).z));
	float	c = (origin(ray).x - center(cyl).x) * (origin(ray).x - center(cyl).x) + (origin(ray).z - center(cyl).z) * (origin(ray).z - center(cyl).z) - (radius(cyl)*radius(cyl));
	float	t;

	t = solution(a, b, c);
	if ((point_at_parameter(ray, t).y > center(cyl).y)
	&& (point_at_parameter(ray, t).y < center(cyl).y + height(cyl))
	&& ((t < t_max) && (t > t_min)))
		return record(t, point_at_parameter(ray, t),
			normal(cyl, point_at_parameter(ray, t)));
	else
		return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
