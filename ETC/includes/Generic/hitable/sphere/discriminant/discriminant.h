#ifndef DISCRIMINANT_H
# define DISCRIMINANT_H

# ifdef IMPLEMETNATION
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "vector_types.h"

float __attribute__((__overloadable__))
discriminant(const float a, const float b, const t_v3sf oc, const t_v3sf radius);
double __attribute__((__overloadable__))
discriminant(const double a, const double b, const t_v3df oc, const t_v3df radius);
t_v3sf __attribute__((__overloadable__))
discriminant(const t_v3sf a, const t_v3sf b, const t_v3sf oc, const t_v3sf radius);
t_v3df __attribute__((__overloadable__))
discriminant(const t_v3df a, const t_v3df b, const t_v3df oc, const t_v3df radius);

# endif

#endif
