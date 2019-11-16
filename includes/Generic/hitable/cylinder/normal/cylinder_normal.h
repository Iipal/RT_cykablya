#ifndef CYLINDER_NORMAL_H
# define CYLINDER_NORMAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
#  include "cylinder_center.h"
#  include "cylinder_top.h"
#  include "ray.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
#  include "ray.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_cylinder_sf cyl,
		register const t_v3sf point);
t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_cylinder_sf cyl,
		register const t_ray_sf ray,
		register const float t);

# endif
#endif
