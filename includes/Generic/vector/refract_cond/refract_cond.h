#ifndef REFRACT_COND_H
# define REFRACT_COND_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_cond(register const t_v2sf x,
			register const t_v2sf n,
			register const float e);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_cond(register const t_v2df x,
			register const t_v2df n,
			register const double e);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_cond(register const t_v3sf x,
			register const t_v3sf n,
			register const float e);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_cond(register const t_v3df x,
			register const t_v3df n,
			register const double e);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_cond(register const t_v4sf x,
			register const t_v4sf n,
			register const float e);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_cond(register const t_v4df x,
			register const t_v4df n,
			register const double e);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
