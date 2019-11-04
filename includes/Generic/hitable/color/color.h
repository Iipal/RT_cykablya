#ifndef COLOR_H
# define COLOR_H

# ifdef IMPLEMETNATION
#  include <stddef.h>
#  include "hit.h"
#  include "record_types.h"
#  include "record_types_internal.h"
#  include "random_float.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include <stddef.h>
#  include "vector_types.h"
#  include "ray_types.h"
#  include "hitable_types.h"

t_v3sf __attribute__((__overloadable__,__target__("avx,avx2")))
color(register const t_ray_sf ray,
	register const union u_hitables * restrict hitables);
t_v3sf __attribute__((__overloadable__,__target__("avx,avx2")))
color(register const t_ray_sf r,
	register const union u_hitables * restrict hitables,
	register const size_t depth);

# endif
#endif
