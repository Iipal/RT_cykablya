#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "point_at_parameter.h"
#endif

t_v3sf __attribute__((__overloadable__,__target__("avx")))
	point_at_parameter(register const struct s_ray_sf *const restrict r,
						register const float t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3sf __attribute__((__overloadable__,__target__("avx")))
	point_at_parameter(register const struct s_ray_sf *const restrict r,
						register const t_v3sf t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3sf __attribute__((__overloadable__,__target__("avx")))
	point_at_parameter(register const t_ray_sf r, register const float t)
{
	return (origin(r) + (t * direction(r)));
}

t_v3sf __attribute__((__overloadable__,__target__("avx")))
	point_at_parameter(register const t_ray_sf r, register const t_v3sf t)
{
	return (origin(r) + (t * direction(r)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
