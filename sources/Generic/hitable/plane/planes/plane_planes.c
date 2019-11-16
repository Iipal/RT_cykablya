#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "plane_planes.h"
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

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
