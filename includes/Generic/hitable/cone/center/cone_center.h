#ifndef CONE_CENTER_H
# define CONE_CENTER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
center(register const t_cone_sf cone);

# endif
#endif
