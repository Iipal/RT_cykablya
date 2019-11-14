#ifndef TETRAHEDRON_CONSTRUCTOR_H
# define TETRAHEDRON_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "hitable.h"
#  include "vector.h"
#  include "ray.h"
#  include "hitable.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
# endif

#ifndef T_TETRAHEDRON_SF
# define T_TETRAHEDRON_SF
typedef float	__attribute__((__ext_vector_type__(9),ALIGN))	t_tetrahedron_sf;
#endif


t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_a(register const t_tetrahedron_sf tetrahedron);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_b(register const t_tetrahedron_sf tetrahedron);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_c(register const t_tetrahedron_sf tetrahedron);
t_tetrahedron_sf __attribute__((CONST,CLONE,ARCH))
tetrahedron(register const t_v3sf a,
			register const t_v3sf b,
			register const t_v3sf c);
t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_tetrahedron_sf t,
		register const t_v3sf point);
t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_tetrahedron_sf t,
	register const t_ray_sf ray,
	register const float t_min,
	register const float t_max,
	register const t_record_sf current_record);


# ifdef DECLARATION
#  include "sphere_types.h"
#  include "vector_types.h"


#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
