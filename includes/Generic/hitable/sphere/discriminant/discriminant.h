#ifndef DISCRIMINANT_H
# define DISCRIMINANT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,ARCH))
discriminant(const float a,
			const float b,
			const t_v3sf oc,
			const t_v3sf radius);
double __attribute__((CONST,CLONE,ARCH))
discriminant(const double a,
			const double b,
			const t_v3df oc,
			const t_v3df radius);
t_v3sf __attribute__((CONST,CLONE,ARCH))
discriminant(const t_v3sf a,
			const t_v3sf b,
			const t_v3sf oc,
			const t_v3sf radius);
t_v3df __attribute__((CONST,CLONE,ARCH))
discriminant(const t_v3df a,
			const t_v3df b,
			const t_v3df oc,
			const t_v3df radius);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
