#ifndef SPHERE_HIT_H
# define SPHERE_HIT_H

# ifdef IMPLEMETNATION
#  include "vector.h"
#  include "ray.h"
#  include "sphere.h"
#  include "record.h"
# endif

# ifdef DECLARATION
#  include "record_types.h"
#  include "sphere_types.h"
#  include "ray_types.h"

t_record_sf __attribute__((__overloadable__,__target__("avx")))
hit(register const t_sphere_sf sphere,
		register const t_ray_sf ray,
		register const float t_min,
		register const float t_max,
		register const t_record_sf current_record);

# endif
#endif
