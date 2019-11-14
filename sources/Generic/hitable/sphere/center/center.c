#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "center.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(register const t_sphere_sf s)
{
	return (s.lo);
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	center(register const t_sphere_df s)
{
	return (s.lo);
}

t_v3sf __attribute__((CONST,CLONE,ARCH))
	center(const struct s_sphere_sf *const restrict s)
{
	return (s->center);
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	center(const struct s_sphere_df *const restrict s)
{
	return (s->center);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
