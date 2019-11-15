#ifndef CONE_CONSTRUCTOR_H
# define CONE_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "hitable.h"
#  include "vector.h"
#  include "ray.h"
#  include "hitable.h"
#  include "solution.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
# endif


# ifdef DECLARATION
#  include "sphere_types.h"
#  include "vector_types.h"
#  ifndef T_CONE_SF
#   define T_CONE_SF

typedef float	__attribute__((__ext_vector_type__(5),ALIGN))	t_cone_sf;

#  endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
center(register const t_cone_sf cone);

float __attribute__((CONST,CLONE,ARCH))
radius(register const t_cone_sf cone);

float __attribute__((CONST,CLONE,ARCH))
height(register const t_cone_sf cone);

t_cone_sf __attribute__((CONST,CLONE,ARCH))
cone(register const t_v3sf center,
	register const float radius,
	register const float height);

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_cone_sf cone,
		register const t_v3sf point);

t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_cone_sf cone,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max,
		register const t_record_sf current_record);

t_v3sf __attribute__((CONST,ARCH))
rotate(register const t_v3sf vec,
		register const t_v3sf rot);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
