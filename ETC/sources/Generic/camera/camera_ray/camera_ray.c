#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "camera_ray.h"
#endif

t_ray_sf __attribute__((CLONE,CONST,ARCH))
	ray(struct s_camera_sf *const restrict camera,
		register const t_v3sf u,
		register const t_v3sf v)
{
	t_ray_sf	t;

	t.lo.xyz = *(camera->origin);
	t.hi.xyz = *(camera->lower_left_corner)
		+ u * *(camera->horizontal)
		+ v * *(camera->vertical)
		- *(camera->origin);
	return (t);
}


static t_v3sf  __attribute__((ARCH,SMALL_STACK))
	random_in_unit_disk(void)
{
	t_v3sf	p;

	while (-42)
	{
	    p = 2.0f * vec(random_float(), random_float(), 0.0f) - vec(1.0f, 1.0f, 0.0f);
	    if (!(dot(p, p) >= 1.0))
	    	break ;
	}
	return p;
}

t_ray_sf __attribute__((CLONE,CONST,ARCH))
	ray(struct s_advanced_camera_sf *const restrict camera,
		register const float s,
		register const float t)
{
	const t_v3sf	rd = camera->lens_radius * random_in_unit_disk();
	const t_v3sf	offset = camera->u * rd.x + camera->v * rd.y;
	t_ray_sf		new_ray;

	new_ray.lo.xyz = camera->origin + offset;
	new_ray.hi.xyz = camera->lower_left_corner
		+ s * camera->horizontal
		+ t * camera->vertical
		- camera->origin - offset;
	return (new_ray);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
