#ifndef PLANE_HIT_H
# define PLANE_HIT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"
#  include "plane_planes.h"
#  include "plane_normal.h"
#  include "record.h"
#  include "ray.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"
#  include "record.h"
#  include "ray.h"

t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_plane_sf plane,
	register const t_ray_sf ray,
	register const t_v2sf time,
	register const t_record_sf current_record);

# endif
#endif
