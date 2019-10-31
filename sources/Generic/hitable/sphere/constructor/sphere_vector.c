#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "sphere_constructor.h"
#endif

t_sphere_sf __attribute__((__overloadable__,__target__("avx")))
	sphere(register const t_v3sf center, register const t_v3sf radius)
{
	t_sphere_sf		s;

	s.lo = center;
	s.hi = radius;
	return (s);
}

t_sphere_sf __attribute__((__overloadable__,__target__("avx")))
	sphere(register const t_v3sf center, register const float radius)
{
	t_sphere_sf		s;

	s.lo = center;
	s.hi = ((__typeof__(center)){ radius, radius, radius });
	return (s);
}

t_sphere_df __attribute__((__overloadable__,__target__("avx")))
	sphere(register const t_v3df center, register const t_v3df radius)
{
	t_sphere_df		s;

	s.lo = center;
	s.hi = radius;
	return (s);
}

t_sphere_df __attribute__((__overloadable__,__target__("avx")))
	sphere(register const t_v3df center, register const double radius)
{
	t_sphere_df		s;

	s.lo = center;
	s.hi = ((__typeof__(center)){ radius, radius, radius });
	return (s);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
