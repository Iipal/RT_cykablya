#ifndef SPHERE_HIT_H
# define SPHERE_HIT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "ray.h"
#  include "sphere.h"
#  include "record.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "record_types.h"
#  include "sphere_types.h"
#  include "ray_types.h"

t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_sphere_sf sphere,
	register const t_ray_sf ray,
	register const t_v2sf time,
	register const t_record_sf current_record);

# endif
#endif
