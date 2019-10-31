#ifndef MATERIAL_CONSTRUCTOR_H
# define MATERIAL_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "material_types.h"
#  include "vector_types.h"

t_material_sf __attribute__((__target__("avx,avx2"),__overloadable__))
material(register const enum e_material current_material,
		register const t_v3sf albedo);
t_material_sf __attribute__((__target__("avx,avx2"),__overloadable__))
material(register const enum e_material current_material,
		register const t_v3sf albedo,
		register const float fuzz);
t_material_sf __attribute__((__target__("avx,avx2"),__overloadable__))
material(register const enum e_material current_material,
		register const float ri);

# endif
#endif
