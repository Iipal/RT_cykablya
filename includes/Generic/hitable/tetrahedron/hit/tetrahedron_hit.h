#ifndef TETRAHEDRON_HIT_H
# define TETRAHEDRON_HIT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"
#  include "tetrahedron_planes.h"
#  include "tetrahedron_normal.h"
#  include "record.h"
#  include "ray.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"
#  include "record.h"
#  include "ray.h"

t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_tetrahedron_sf tetrahedron,
	register const t_ray_sf ray,
	register const t_v2sf time,
	register const t_record_sf current_record);

# endif
#endif
