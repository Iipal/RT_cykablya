#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cone_normal.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_cone_sf cone,
			register const t_v3sf point)
{
    register float r;

    r = sqroot((point.x - center(cone).x)
    * (point.x - center(cone).x)
    + (point.z - center(cone).z)
    * (point.z - center(cone).z));
    return (normalize(vec(point.x-center(cone).x,
    	r*(radius(cone)/height(cone)),
    	point.z-center(cone).z)));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
