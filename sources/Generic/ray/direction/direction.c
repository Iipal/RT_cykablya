#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "direction.h"
#endif

t_v3sf __attribute__((__overloadable__,__target__("avx")))
	direction(register const t_ray_sf r)
{
	return (r.hi);
}

t_v3df __attribute__((__overloadable__,__target__("avx")))
	direction(const t_ray_df r)
{
	return (r.hi);
}

t_v3sf __attribute__((__overloadable__))
	direction(const struct s_ray_sf *const restrict r)
{
	return (r->b);
}

t_v3df __attribute__((__overloadable__))
	direction(const struct s_ray_df *const restrict r)
{
	return (r->b);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif