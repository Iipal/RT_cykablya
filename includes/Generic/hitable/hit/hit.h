#ifndef HIT_H
# define HIT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include <stddef.h>
#  include "cone_constructor.h"
#  include "record_types_internal.h"
#  include "hitable_types_internal.h"
#  include "vector_types_internal.h"
#  include "vector_types.h"
#  include "sphere.h"
#  include "cone.h"
#  include "cylinder.h"
#  include "tetrahedron.h"
#  include "plane.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "ray_types.h"
#  include "record_types.h"
#  include "hitable_types.h"

t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const union u_hitables * restrict hitables,
	register const t_ray_sf ray,
	register const float t_min,
	register const float t_max);

# endif
#endif
