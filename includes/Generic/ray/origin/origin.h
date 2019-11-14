#ifndef ORIGIN_H
# define ORIGIN_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "ray_types_internal.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "ray_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
origin(register const t_ray_sf r);
t_v3df __attribute__((CONST,CLONE,ARCH))
origin(const t_ray_df r);
t_v3sf __attribute__((PURE,CLONE,ARCH))
origin(const struct s_ray_sf *const restrict r);
t_v3df __attribute__((PURE,CLONE,ARCH))
origin(const struct s_ray_df *const restrict r);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
