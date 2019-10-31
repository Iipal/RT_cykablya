#ifndef REFRACT_REFLECT_H
# define REFRACT_REFLECT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_reflect(register const t_v2sf x,
				register const t_v2sf n,
				register const float e,
				register const t_v2sf reflect);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_reflect(register const t_v2df x,
				register const t_v2df n,
				register const double e,
				register const t_v2df reflect);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_reflect(register const t_v3sf x,
				register const t_v3sf n,
				register const float e,
				register const t_v3sf reflect);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_reflect(register const t_v3df x,
				register const t_v3df n,
				register const double e,
				register const t_v3df reflect);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_reflect(register const t_v4sf x,
				register const t_v4sf n,
				register const float e,
				register const t_v4sf reflect);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract_reflect(register const t_v4df x,
				register const t_v4df n,
				register const double e,
				register const t_v4df reflect);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
