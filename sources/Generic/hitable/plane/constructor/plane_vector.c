#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "plane_constructor.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	plane_a(register const t_plane_sf plane)
{
	return (vec(plane[0], plane[1], plane[2]));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	plane_b(register const t_plane_sf plane)
{
	return (vec(plane[3], plane[4], plane[5]));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	plane_c(register const t_plane_sf plane)
{
	return (vec(plane[6], plane[7], plane[8]));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	plane_d(register const t_plane_sf plane)
{
	return (vec(plane[9], plane[10], plane[11]));
}

t_plane_sf __attribute__((CONST,CLONE,ARCH))
	plane(register const t_v3sf a,
			register const t_v3sf b,
			register const t_v3sf c,
			register const t_v3sf d)
{
	return (__extension__((t_plane_sf){
		a.x, a.y, a.z,
		b.x, b.y, b.z,
		c.x, c.y, c.z,
		d.x, d.y, d.z,
	}));
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_plane_sf plane,
			register const t_v3sf point)
{
    return normalize(cross(
    	plane_b(plane) - plane_a(plane),
    	plane_c(plane) - plane_a(plane)));
}

static _Bool __attribute__((CONST,CLONE,ARCH))
	is_inside(register const t_plane_sf p,
			register const t_v3sf q)
{
	t_v3sf	n = normal(p, q);

	t_v3sf	ua = plane_b(p) - plane_a(p);
	t_v3sf	ub = plane_c(p) - plane_b(p);
	t_v3sf	uc = plane_d(p) - plane_c(p);
	t_v3sf	ud = plane_a(p) - plane_d(p);

	t_v3sf	va = q - plane_a(p);
	t_v3sf	vb = q - plane_b(p);
	t_v3sf	vc = q - plane_c(p);
	t_v3sf	vd = q - plane_d(p);

    return ((dot(cross(ua, va), n) > 0)
    && (dot(cross(ub, vb), n) > 0)
    && (dot(cross(uc, vc), n) > 0)
    && (dot(cross(ud, vd), n) > 0));
}

t_record_sf __attribute__((CONST,CLONE,ARCH))
	hit(register const t_plane_sf plane,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max,
		register const t_record_sf current_record)
{

	t_v3sf	n = normal(plane, origin(ray));
	t_v3sf	v_dif = plane_a(plane) - origin(ray);
	float	v_dot_n = dot(direction(ray), n);
	float	t;

	if (__builtin_fabs(v_dot_n) < 1.e-4f)
		return (record(current_record));
	t = dot(v_dif, n) / v_dot_n;
	if (__builtin_fabs(t) < 0.0001f)
		return (record(current_record));
	if ((t < t_max) && (t > t_min)
	&& is_inside(plane, point_at_parameter(ray, t)))
		return record(t, point_at_parameter(ray, t),
			normal(plane, point_at_parameter(ray, t)));
	else
		return (record(current_record));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
