#ifndef HORIZONTAL_H
# define HORIZONTAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*horizontal(void);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*horizontal(register const float half_width);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*horizontal(register const t_v3sf vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
