#ifndef LENGTH_SQUARED_H
# define LENGTH_SQUARED_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "dot.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v2sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v2df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v3sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v3df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v4sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v4df vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
