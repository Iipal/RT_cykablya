#ifndef COLOR_TO_RGB_H
# define COLOR_TO_RGB_H

# ifdef IMPLEMETNATION
#  include "vector_types.h"
#  if defined(__GNUC__) && defined(__clang__)
#   ifndef T_V3SU
#    define T_V3SU
typedef unsigned __attribute__((__ext_vector_type__(3),__aligned__))    t_v3su;
#   endif
#  elif defined(__GNUC__) && !defined(__clang__)
#   ifndef T_V3SU
#    define T_V3SU
typedef unsigned __attribute__((__vector_size__(sizeof(unsigned)*4UL))) t_v3su;
#   endif
#  else
#   ifndef T_V3SU
#    define T_V3SU
typedef unsigned													    t_v3su[3];
#    endif
#  endif
# endif

# ifdef DECLARATION
#  include "vector_types.h"

unsigned __attribute__((__target__("avx,avx2"),__overloadable__))
color_to_rgb(register const t_v3sf col);

# endif

#endif
