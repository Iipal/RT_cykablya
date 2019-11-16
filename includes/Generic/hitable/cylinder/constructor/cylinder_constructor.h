#ifndef CYLINDER_CONSTRUCTOR_H
# define CYLINDER_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"

t_cylinder_sf __attribute__((CONST,CLONE,ARCH))
cylinder(register const t_v3sf center,
		register const float radius,
		register const float height);
t_cylinder_sf __attribute__((CONST,CLONE,ARCH))
cylinder(register const t_v3sf center,
		register const t_v3sf top,
		register const float radius);

# endif
#endif
