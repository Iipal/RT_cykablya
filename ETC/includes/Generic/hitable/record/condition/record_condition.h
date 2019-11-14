#ifndef RECORD_CONDITION_H
# define RECORD_CONDITION_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "record_types.h"

_Bool __attribute__((CONST,CLONE,ARCH))
condition(register const t_record_sf record);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
