#ifndef SOLUTION_H
# define SOLUTION_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"

float __attribute__((CONST,CLONE,ARCH))
solution(register const float a,
		register const float b,
		register const float c);

# endif
#endif
