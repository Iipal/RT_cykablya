#ifndef VERTICAL_H
# define VERTICAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*vertical(void);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*vertical(register const float half_height);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*vertical(register const t_v3sf vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
