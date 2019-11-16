#ifndef TETRAHEDRON_NORMAL_H
# define TETRAHEDRON_NORMAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"
#  include "tetrahedron_planes.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_tetrahedron_sf t);

# endif
#endif
