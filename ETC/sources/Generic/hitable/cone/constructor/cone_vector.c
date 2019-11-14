#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cone_constructor.h"
#endif

static t_v3sf __attribute__((CONST,ARCH))
	rotate_x(register const t_v3sf v,
			register const float x)
{
	return (vec(
		v.x,
		v.y * __builtin_cosf(x) - v.z * __builtin_sinf(x),
		v.y * __builtin_cosf(x) + v.z * __builtin_sinf(x)
	));
}

static t_v3sf __attribute__((CONST,ARCH))
	rotate_y(register const t_v3sf v,
			register const float y)
{
	return (vec(
		v.x * __builtin_cosf(y) + v.z * __builtin_sinf(y),
		v.y,
		v.x * -__builtin_sinf(y) + v.z * __builtin_cosf(y)
	));
}

static t_v3sf __attribute__((CONST,ARCH))
	rotate_z(register const t_v3sf v,
			register const float z)
{
	return (vec(
		v.x * __builtin_cosf(z) - v.y * __builtin_sinf(z),
		v.x * __builtin_sinf(z) + v.y * __builtin_cosf(z),
		v.z
	));
}

t_v3sf __attribute__((CONST,ARCH))
	rotate(register const t_v3sf vec,
			register const t_v3sf rot)
{
	return (vec * rotate_x(vec, rot.x)
				* rotate_y(vec, rot.y)
				* rotate_z(vec, rot.z));
}



t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(register const t_cone_sf cone)
{
	return (cone.xyz);
}

float __attribute__((CONST,CLONE,ARCH))
	radius(register const t_cone_sf cone)
{
	return (cone[3]);
}

float __attribute__((CONST,CLONE,ARCH))
	height(register const t_cone_sf cone)
{
	return (cone[4]);
}

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

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_cone_sf cone,
			register const t_v3sf point)
{
    float r = sqroot((point.x-center(cone).x)*(point.x-center(cone).x)
    				+ (point.z-center(cone).z)*(point.z-center(cone).z));
    t_v3sf n = { point.x-center(cone).x, r*(radius(cone)/height(cone)), point.z-center(cone).z };
    return normalize(n);
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
	hit(register const t_cone_sf cone,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max,
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
	&& ((t < t_max) && (t > t_min)))
		return record(t, point_at_parameter(ray, t),
			normal(cone, point_at_parameter(ray, t)));
	else
		return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
