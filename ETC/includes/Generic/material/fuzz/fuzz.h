#ifndef FUZZ_H
# define FUZZ_H

# ifdef IMPLEMETNATION
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "material_types.h"
#  include "vector_types.h"

float __attribute__((__target__("avx")))
fuzz(register const t_material_sf material);

# endif
#endif
