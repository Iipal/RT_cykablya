#ifndef CROSS_H
# define CROSS_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v2sf x, register const t_v2sf y);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v2df x, register const t_v2df y);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v3sf x, register const t_v3sf y);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v3df x, register const t_v3df y);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
