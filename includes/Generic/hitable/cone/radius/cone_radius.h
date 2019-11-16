#ifndef CONE_RADIUS_H
# define CONE_RADIUS_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"

float __attribute__((CONST,CLONE,ARCH))
radius(register const t_cone_sf cone);

# endif
#endif
