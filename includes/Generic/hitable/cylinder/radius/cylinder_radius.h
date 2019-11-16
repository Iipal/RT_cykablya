#ifndef CYLINDER_RADIUS_H
# define CYLINDER_RADIUS_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"

float __attribute__((CONST,CLONE,ARCH))
radius(register const t_cylinder_sf cylinder);

# endif
#endif
