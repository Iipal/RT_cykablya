#ifndef POINT_AT_PARAMETER_H
# define POINT_AT_PARAMETER_H

# ifdef IMPLEMETNATION
#  include "ray_types_internal.h"
#  include "vector_types.h"
#  include "origin.h"
#  include "direction.h"
# endif

# ifdef DECLARATION

#  include "vector_types.h"
#  include "ray_types.h"

t_v3sf __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(register const struct s_ray_sf *const restrict r,
					register const float t);
t_v3sf __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(register const struct s_ray_sf *const restrict r,
					register const t_v3sf t);
t_v3sf __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(register const t_ray_sf r, register const float t);
t_v3sf __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(register const t_ray_sf r, register const t_v3sf t);
t_v3df __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(register const struct s_ray_df *const restrict r,
					register const double t);
t_v3df __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(register const struct s_ray_df *const restrict r,
					register const t_v3df t);
t_v3df __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(const t_ray_df r,
					register const double t);
t_v3df __attribute__((__overloadable__,__target__("avx")))
point_at_parameter(const t_ray_df r,
					register const t_v3df t);

# endif

#endif
