#ifndef MATERIAL_TYPES_INTERNAL_H
# define MATERIAL_TYPES_INTERNAL_H
# include "vector_types.h"
# include "vector_int_types.h"
# include "material_types.h"

# ifndef T_MATERIAL_SI
#  define T_MATERIAL_SI
typedef t_v8si	__attribute__((__aligned__(32)))	t_material_si;
# endif

#endif
