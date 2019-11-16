#ifndef CONE_NORMAL_H
# define CONE_NORMAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
#  include "cone_center.h"
#  include "cone_radius.h"
#  include "cone_height.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_cone_sf cone,
		register const t_v3sf point);

# endif
#endif
