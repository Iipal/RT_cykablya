#ifndef RECORD_MATERIAL_H
# define RECORD_MATERIAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "material.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "material.h"
#  include "record_types.h"

enum e_material __attribute__((CONST,CLONE,ARCH))
material(register const t_record_sf record);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
