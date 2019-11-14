#ifndef CAMERA_ORIGIN_H
# define CAMERA_ORIGIN_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*origin(void);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*origin(register const t_v3sf vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
