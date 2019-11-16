#ifndef PLANE_NORMAL_H
# define PLANE_NORMAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"
#  include "plane_planes.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_plane_sf plane);

# endif
#endif
