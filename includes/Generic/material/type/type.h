#ifndef TYPE_H
# define TYPE_H

# ifdef IMPLEMETNATION
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "material_types.h"
#  include "vector_types.h"

enum e_material __attribute__((__target__("avx,avx2")))
type(register const t_material_sf material);

# endif
#endif
