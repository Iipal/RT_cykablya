#ifndef RAY_CONSTRUCTOR_H
# define RAY_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include <stdlib.h>
#  include "ray_types_internal.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "ray_types.h"
#  include "vector_types.h"

struct s_ray_sf __attribute__((PURE,CLONE,ARCH))
*ray(void);
struct s_ray_sf __attribute__((PURE,CLONE,ARCH))
*ray(const float init);
struct s_ray_df __attribute__((PURE,CLONE,ARCH))
*ray(const double init);

t_ray_sf __attribute__((CONST,CLONE,ARCH))
ray(register const t_v3sf a, register const t_v3sf b);
t_ray_sf __attribute__((PURE,CLONE,ARCH))
ray(const t_v3sf v[static 2]);
t_ray_df __attribute__((CONST,CLONE,ARCH))
ray(register const t_v3df a, register const t_v3df b);
t_ray_df __attribute__((PURE,CLONE,ARCH))
ray(const t_v3df v[static 2]);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
