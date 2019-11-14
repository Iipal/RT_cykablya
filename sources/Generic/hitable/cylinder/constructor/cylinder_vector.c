#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_constructor.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(register const t_cylinder_sf cylinder)
{
	return (cylinder.lo.xyz);
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	top(register const t_cylinder_sf cylinder)
{
	return (cylinder.hi.xyz);
}

static t_v3sf __attribute__((CONST,CLONE,ARCH))
	axis(register const t_cylinder_sf cylinder)
{
	return (normalize(top(cylinder) - center(cylinder)));
}

float __attribute__((CONST,CLONE,ARCH))
	radius(register const t_cylinder_sf cylinder)
{
	return (cylinder.lo.w);
}

float __attribute__((CONST,CLONE,ARCH))
	height(register const t_cylinder_sf cylinder)
{
	return (length(top(cylinder) - center(cylinder)));
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


t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_cylinder_sf cyl,
			register const t_v3sf point)
{
	(void)point;
	return normalize(vec(point.x - center(cyl).x,
						0.0f,
						point.z - center(cyl).z));
}

static t_v3sf __attribute__((CONST,CLONE,ARCH))
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
	const t_v3sf	oc = origin(ray) - center(cyl);
	const float		a = length_squared(direction(ray)) - dot(direction(ray), axis(cyl)) * dot(direction(ray), axis(cyl));
	const float		b = 2.0f * (dot(direction(ray), oc) - dot(direction(ray), axis(cyl)) * dot(oc, axis(cyl)));
	const float 	c = length_squared(oc) - dot(oc, axis(cyl)) * dot(oc, axis(cyl)) - radius(cyl) * radius(cyl);
	float			t = solution(a, b, c);

	if ((point_at_parameter(ray, t).y > center(cyl).y)
	&& (point_at_parameter(ray, t).y < center(cyl).y + height(cyl))
	&& (t < t_max) && (t > t_min))
		return record(t, point_at_parameter(ray, t),
			normal(cyl, ray, t));
	else
		return (record(current_record));
}


#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
