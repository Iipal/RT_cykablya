#ifndef CAMERA_RAY_H
# define CAMERA_RAY_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "random_float.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
#  include "camera_types_internal.h"
#  include "vector_types.h"
#  include "ray_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "camera_types.h"
#  include "vector_types.h"
#  include "ray_types.h"

t_ray_sf __attribute__((CLONE,CONST,ARCH))
ray(struct s_camera_sf *const restrict camera,
	register const t_v3sf u,
	register const t_v3sf v);

t_ray_sf __attribute__((CLONE,CONST,ARCH))
ray(struct s_advanced_camera_sf *const restrict camera,
	register const float s,
	register const float t);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
