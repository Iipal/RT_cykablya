#ifndef VEC_DOT_H
# define VEC_DOT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vec_reduce_add.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_dot(register const t_v2sf x, register const t_v2sf y);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_dot(register const t_v2df x, register const t_v2df y);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_dot(register const t_v3sf x, register const t_v3sf y);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_dot(register const t_v3df x, register const t_v3df y);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_dot(register const t_v4sf x, register const t_v4sf y);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_dot(register const t_v4df x, register const t_v4df y);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
