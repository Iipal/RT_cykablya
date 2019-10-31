#ifndef DIRECTION_H
# define DIRECTION_H

# ifdef IMPLEMETNATION
#  include "ray_types_internal.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION

#  include "vector_types.h"
#  include "ray_types.h"

t_v3sf __attribute__((__overloadable__,__target__("avx")))
	direction(register const t_ray_sf r);
t_v3df __attribute__((__overloadable__,__target__("avx")))
	direction(const t_ray_df r);
t_v3sf __attribute__((__overloadable__))
	direction(const struct s_ray_sf *const restrict r);
t_v3df __attribute__((__overloadable__))
	direction(const struct s_ray_df *const restrict r);

# endif

#endif
