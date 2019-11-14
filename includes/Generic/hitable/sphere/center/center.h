#ifndef CENTER_H
# define CENTER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "sphere_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "sphere_types.h"
#  include "vector_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
center(register const t_sphere_sf s);
t_v3df __attribute__((CONST,CLONE,ARCH))
center(register const t_sphere_df s);
t_v3sf __attribute__((CONST,CLONE,ARCH))
center(const struct s_sphere_sf *const restrict s);
t_v3df __attribute__((CONST,CLONE,ARCH))
center(const struct s_sphere_df *const restrict s);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
