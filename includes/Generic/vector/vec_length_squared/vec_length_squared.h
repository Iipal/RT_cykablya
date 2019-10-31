#ifndef VEC_LENGTH_SQUARED_H
# define VEC_LENGTH_SQUARED_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vec_dot.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_length_squared(register const t_v2sf vec);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_length_squared(register const t_v2df vec);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_length_squared(register const t_v3sf vec);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_length_squared(register const t_v3df vec);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_length_squared(register const t_v4sf vec);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_length_squared(register const t_v4df vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
