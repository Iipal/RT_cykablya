#ifndef CYLINDER_CENTER_H
# define CYLINDER_CENTER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
center(register const t_cylinder_sf cylinder);

# endif
#endif
