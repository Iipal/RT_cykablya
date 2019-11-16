#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cone_hit.h"
#endif

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_cone_sf cone,
		register const t_ray_sf ray,
		register const t_v2sf time,
		register const t_record_sf current_record)
{
	const float	a = origin(ray).x - center(cone).x;
	const float	b = origin(ray).z - center(cone).z;
	const float	c = height(cone) - origin(ray).y + center(cone).y;
	float		tan;
	float		t;

	tan =  (radius(cone) / height(cone)) * (radius(cone) / height(cone));
	t = solution(
		(direction(ray).x * direction(ray).x)
		+ (direction(ray).z * direction(ray).z)
		- (tan * (direction(ray).y * direction(ray).y)),
		(2.0f * a * direction(ray).x)
		+ (2.0f * b * direction(ray).z)
		+ (2.0f * tan * c * direction(ray).y),
		(a * a) + (b * b) - (tan * (c * c)));
	if ((point_at_parameter(ray, t).y > center(cone).y)
	&& (point_at_parameter(ray, t).y < center(cone).y + height(cone))
	&& ((t < time.y) && (t > time.x)))
		return record(t, point_at_parameter(ray, t),
			normal(cone, point_at_parameter(ray, t)));
	else
		return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
