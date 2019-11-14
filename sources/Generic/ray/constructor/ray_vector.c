#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "ray_constructor.h"
#endif

t_ray_sf __attribute__((CONST,CLONE,ARCH))
	ray(register const t_v3sf a, register const t_v3sf b)
{
	t_ray_sf	t;

	t.lo = a;
	t.hi = b;
	return (t);
}

t_ray_sf __attribute__((PURE,CLONE,ARCH))
	ray(const t_v3sf v[static 2])
{
	return (((const union u_ray_sf){
		.aliased = *(const t_ray_sf_a*)v }).aligned);
}

t_ray_df __attribute__((CONST,CLONE,ARCH))
	ray(register const t_v3df a, register const t_v3df b)
{
	t_ray_df	t;

	t.lo = a;
	t.hi = b;
	return (t);
}

t_ray_df __attribute__((PURE,CLONE,ARCH))
	ray(const t_v3df v[static 2])
{
	return (((const union u_ray_df){
		.aliased = *(const t_ray_df_a*)v }).aligned);
}


#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
