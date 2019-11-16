#ifndef TETRAHEDRON_PLANES_H
# define TETRAHEDRON_PLANES_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_a(register const t_tetrahedron_sf tetrahedron);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_b(register const t_tetrahedron_sf tetrahedron);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_c(register const t_tetrahedron_sf tetrahedron);

# endif
#endif
