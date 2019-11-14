#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "tetrahedron_constructor.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	plane_a(register const t_tetrahedron_sf tetrahedron)
{
	return (vec(tetrahedron[0], tetrahedron[1], tetrahedron[2]));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	plane_b(register const t_tetrahedron_sf tetrahedron)
{
	return (vec(tetrahedron[3], tetrahedron[4], tetrahedron[5]));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	plane_c(register const t_tetrahedron_sf tetrahedron)
{
	return (vec(tetrahedron[6], tetrahedron[7], tetrahedron[8]));
}

t_tetrahedron_sf __attribute__((CONST,CLONE,ARCH))
	tetrahedron(register const t_v3sf a,
				register const t_v3sf b,
				register const t_v3sf c)
{
	return (__extension__((t_tetrahedron_sf){
		a.x, a.y, a.z,
		b.x, b.y, b.z,
		c.x, c.y, c.z
	}));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_tetrahedron_sf t,
			register const t_v3sf point)
{
    return normalize(cross(
    	plane_b(t) - plane_a(t),
    	plane_c(t) - plane_a(t)));
}

static _Bool __attribute__((CONST,CLONE,ARCH))
	is_inside(register const t_tetrahedron_sf t,
			register const t_v3sf q)
{
	t_v3sf	n = normal(t, q);

	t_v3sf	ua = plane_b(t) - plane_a(t);
	t_v3sf	ub = plane_c(t) - plane_b(t);
	t_v3sf	uc = plane_a(t) - plane_c(t);

	t_v3sf	va = q - plane_a(t);
	t_v3sf	vb = q - plane_b(t);
	t_v3sf	vc = q - plane_c(t);

    return ((dot(cross(ua, va), n) > 0)
    && (dot(cross(ub, vb), n) > 0)
    && (dot(cross(uc, vc), n) > 0));
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_tetrahedron_sf tetrahedron,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max,
		register const t_record_sf current_record)
{

	t_v3sf	n = normal(tetrahedron, origin(ray));
	t_v3sf	v_dif = plane_a(tetrahedron) - origin(ray);
	float	v_dot_n = dot(direction(ray), n);
	float	t;

	if (__builtin_fabs(v_dot_n) < 1.e-4f)
		return (record(current_record));
	t = dot(v_dif, n) / v_dot_n;
	if (__builtin_fabs(t) < 0.0001f)
		return (record(current_record));
	if ((t < t_max) && (t > t_min)
	&& is_inside(tetrahedron, point_at_parameter(ray, t)))
		return record(t, point_at_parameter(ray, t),
			normal(tetrahedron, point_at_parameter(ray, t)));
	else
		return (record(current_record));
}




#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
