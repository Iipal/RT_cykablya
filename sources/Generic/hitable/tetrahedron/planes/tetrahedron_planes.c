#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "tetrahedron_planes.h"
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

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
