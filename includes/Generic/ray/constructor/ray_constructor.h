#ifndef RAY_CONSTRUCTOR_H
# define RAY_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include <stdlib.h>
#  include "ray_types_internal.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION
#  include "ray_types.h"
#  include "vector_types.h"

struct s_ray_sf __attribute__((__overloadable__))
*ray(void);
struct s_ray_sf __attribute__((__overloadable__))
*ray(const float init);
struct s_ray_df __attribute__((__overloadable__))
*ray(const double init);

t_ray_sf __attribute__((__overloadable__,__target__("avx")))
ray(register const t_v3sf a, register const t_v3sf b);
t_ray_sf __attribute__((__overloadable__,__target__("avx")))
ray(const t_v3sf v[static 2]);
t_ray_df __attribute__((__overloadable__,__target__("avx")))
ray(register const t_v3df a, register const t_v3df b);
t_ray_df __attribute__((__overloadable__,__target__("avx")))
ray(const t_v3df v[static 2]);

# endif
#endif
