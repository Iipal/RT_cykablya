#ifndef RI_H
# define RI_H

# ifdef IMPLEMETNATION
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "material_types.h"
#  include "vector_types.h"

float __attribute__((__target__("avx")))
ri(register const t_material_sf material);

# endif
#endif
