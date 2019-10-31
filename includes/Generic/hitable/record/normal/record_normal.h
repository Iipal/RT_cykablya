#ifndef RECORD_NORMAL_H
# define RECORD_NORMAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "record_types.h"
#  include "vector_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_record_sf record);
t_v3df __attribute__((CONST,CLONE,ARCH))
normal(register const t_record_df record);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
