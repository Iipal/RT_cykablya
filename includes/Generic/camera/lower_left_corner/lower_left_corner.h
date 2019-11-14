#ifndef LOWER_LEFT_CORNER_H
# define LOWER_LEFT_CORNER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*lower_left_corner(void);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*lower_left_corner(register const float half_width,
						register const float half_height);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*lower_left_corner(register const t_v3sf vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
