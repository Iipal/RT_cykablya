#ifndef DOT_H
# define DOT_H

# ifdef IMPLEMETNATION
#  include "reduce_add.h"
#  include "attributes.h"
# endif

# ifdef DECLARATION
#  include "vector_types.h"
#  include "attributes.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
dot(register const t_v2sf x, register const t_v2sf y);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
dot(register const t_v2df x, register const t_v2df y);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
dot(register const t_v3sf x, register const t_v3sf y);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
dot(register const t_v3df x, register const t_v3df y);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
dot(register const t_v4sf x, register const t_v4sf y);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
dot(register const t_v4df x, register const t_v4df y);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
