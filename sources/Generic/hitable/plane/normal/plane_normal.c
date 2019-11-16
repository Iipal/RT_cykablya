#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "plane_normal.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_plane_sf plane)
{
    return normalize(cross(
    	plane_b(plane) - plane_a(plane),
    	plane_c(plane) - plane_a(plane)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
