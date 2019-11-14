#ifndef COLOR_TO_RGB_H
# define COLOR_TO_RGB_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "vector_types.h"
#  ifndef T_V3SU
#   define T_V3SU
typedef unsigned __attribute__((__ext_vector_type__(3),__aligned__))    t_v3su;
#  endif
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

unsigned __attribute__((CONST,SMALL_STACK,ARCH))
color_to_rgb(register const t_v3sf col);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
