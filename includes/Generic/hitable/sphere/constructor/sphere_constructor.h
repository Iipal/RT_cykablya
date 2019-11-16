#ifndef SPHERE_CONSTRUCTOR_H
# define SPHERE_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "sphere_types_internal.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "sphere_types.h"
#  include "vector_types.h"

t_sphere_sf __attribute__((CONST,CLONE,ARCH))
sphere(register const t_v3sf center, register const t_v3sf radius);
t_sphere_sf __attribute__((CONST,CLONE,ARCH))
sphere(register const t_v3sf center, register const float radius);
t_sphere_df __attribute__((CONST,CLONE,ARCH))
sphere(register const t_v3df center, register const t_v3df radius);
t_sphere_df __attribute__((CONST,CLONE,ARCH))
sphere(register const t_v3df center, register const double radius);
struct s_sphere_sf __attribute__((CLONE,ARCH))
*sphere(void);
struct s_sphere_sf __attribute__((CLONE,ARCH))
*sphere(const float f);
struct s_sphere_df __attribute__((CLONE,ARCH))
*sphere(const double f);

# endif
#endif
