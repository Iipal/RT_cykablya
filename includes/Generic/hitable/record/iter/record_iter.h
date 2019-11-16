#ifndef RECORD_ITER_H
# define RECORD_ITER_H

# ifdef IMPLEMETNATION
#  include <stddef.h>
#  include "attributes.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include <stddef.h>
#  include "attributes.h"
#  include "record_types.h"

size_t __attribute__((CONST,CLONE,ARCH))
iter(register const t_record_sf record);

# endif
#endif
