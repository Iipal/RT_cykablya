#ifndef CYLINDER_CONSTRUCTOR_H
# define CYLINDER_CONSTRUCTOR_H

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

#ifndef T_CYLINDER_SF
# define T_CYLINDER_SF
typedef float	__attribute__((__ext_vector_type__(7),ALIGN))	t_cylinder_sf;
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
center(register const t_cylinder_sf cylinder);
t_v3sf __attribute__((CONST,CLONE,ARCH))
top(register const t_cylinder_sf cylinder);
float __attribute__((CONST,CLONE,ARCH))
radius(register const t_cylinder_sf cylinder);
float __attribute__((CONST,CLONE,ARCH))
height(register const t_cylinder_sf cylinder);
t_cylinder_sf __attribute__((CONST,CLONE,ARCH))
cylinder(register const t_v3sf center,
		register const float radius,
		register const float height);
t_cylinder_sf __attribute__((CONST,CLONE,ARCH))
cylinder(register const t_v3sf center,
		register const t_v3sf top,
		register const float radius);
t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_cylinder_sf cyl,
		register const t_v3sf point);
t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_cylinder_sf cyl,
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
