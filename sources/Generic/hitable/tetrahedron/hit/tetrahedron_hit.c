#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "tetrahedron_hit.h"
#endif

static _Bool __attribute__((CONST,CLONE,ARCH))
	is_inside(register const t_tetrahedron_sf t,
			register const t_v3sf q)
{
	return (
	(dot(cross(plane_b(t) - plane_a(t), q - plane_a(t)), normal(t)) > 0)
	&& (dot(cross(plane_c(t) - plane_b(t), q - plane_b(t)), normal(t)) > 0)
	&& (dot(cross(plane_a(t) - plane_c(t), q - plane_c(t)), normal(t)) > 0));
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_tetrahedron_sf tetrahedron,
		register const t_ray_sf ray,
		register const t_v2sf time,
		register const t_record_sf current_record)
{

	t_v3sf	n = normal(tetrahedron);
	t_v3sf	v_dif = plane_a(tetrahedron) - origin(ray);
	float	v_dot_n = dot(direction(ray), n);
	float	t;

	if (__builtin_fabsf(v_dot_n) < 1.e-4f)
		return (record(current_record));
	t = dot(v_dif, n) / v_dot_n;
	if (__builtin_fabsf(t) < 0.0001f)
		return (record(current_record));
	if ((t < time.y) && (t > time.x)
	&& is_inside(tetrahedron, point_at_parameter(ray, t)))
		return record(t, point_at_parameter(ray, t),
			normal(tetrahedron));
	else
		return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
