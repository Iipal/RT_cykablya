#ifndef CAMERA_CONSTRUCTOR_H
# define CAMERA_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "global_definitions.h"
#  include "vector.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
#  include "camera_types_internal.h"
#  include "lower_left_corner.h"
#  include "horizontal.h"
#  include "vertical.h"
#  include "camera_origin.h"
# endif

# ifdef DECLARATION
#  include "camera_types.h"

struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
*camera(void);
struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
*camera(register const float fov, register const float aspect_ratio);
struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
*camera(register const t_v3sf look_from,
		register const t_v3sf look_at,
		register const t_v3sf position,
		register const float fov,
		register const float aspect_ratio);
struct s_advanced_camera_sf __attribute__((CLONE))
*camera(register const t_v3sf look_from,
		register const t_v3sf look_at,
		register const t_v3sf position,
		register const t_v4sf params);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
