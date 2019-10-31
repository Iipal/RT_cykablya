#ifndef ALBEDO_H
# define ALBEDO_H

# ifdef IMPLEMETNATION
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "material_types.h"
#  include "vector_types.h"

t_v3sf __attribute__((__target__("avx")))
albedo(register const t_material_sf material);

# endif
#endif
