#ifndef CONE_CONSTRUCTOR_H
# define CONE_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"

t_cone_sf __attribute__((CONST,CLONE,ARCH))
cone(register const t_v3sf center,
	register const float radius,
	register const float height);

# endif
#endif
