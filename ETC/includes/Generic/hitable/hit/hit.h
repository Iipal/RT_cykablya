#ifndef HIT_H
# define HIT_H

# ifdef IMPLEMETNATION
#  include <stddef.h>
# include "cone_constructor.h"
#  include "record_types_internal.h"
#  include "hitable_types_internal.h"
#  include "vector_types_internal.h"
#  include "vector_types.h"
#  include "sphere_hit.h"
# endif

# ifdef DECLARATION
#  include "ray_types.h"
#  include "record_types.h"
#  include "hitable_types.h"

t_record_sf __attribute__((__overloadable__,__target__("avx")))
hit(register const union u_hitables *const restrict hitables,
	register const t_ray_sf ray,
	register const float t_min,
	register const float t_max);

# endif
#endif
