#ifndef CYLINDER_HEIGHT_H
# define CYLINDER_HEIGHT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
#  include "cylinder_center.h"
#  include "cylinder_top.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"

float __attribute__((CONST,CLONE,ARCH))
height(register const t_cylinder_sf cylinder);

# endif
#endif
