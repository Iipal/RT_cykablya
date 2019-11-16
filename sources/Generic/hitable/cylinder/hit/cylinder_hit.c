#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cylinder_hit.h"
#endif

static t_v3sf __attribute__((CONST,CLONE,ARCH))
	axis(register const t_cylinder_sf cylinder)
{
	return (normalize(top(cylinder) - center(cylinder)));
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_cylinder_sf cyl,
		register const t_ray_sf ray,
		register const t_v2sf time,
		register const t_record_sf current_record)
{
	const t_v3sf	oc = origin(ray) - center(cyl);
	const float		a = length_squared(direction(ray)) - dot(direction(ray), axis(cyl)) * dot(direction(ray), axis(cyl));
	const float		b = 2.0f * (dot(direction(ray), oc) - dot(direction(ray), axis(cyl)) * dot(oc, axis(cyl)));
	const float 	c = length_squared(oc) - dot(oc, axis(cyl)) * dot(oc, axis(cyl)) - radius(cyl) * radius(cyl);
	float			t = solution(a, b, c);

	if ((point_at_parameter(ray, t).y > center(cyl).y)
	&& (point_at_parameter(ray, t).y < center(cyl).y + height(cyl))
	&& (t < time.y) && (t > time.x))
		return record(t, point_at_parameter(ray, t),
			normal(cyl, ray, t));
	else
		return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
