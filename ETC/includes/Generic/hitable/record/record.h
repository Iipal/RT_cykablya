#ifndef RECORD_H
# define RECORD_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "record_types.h"
#  include "vector_types.h"

t_record_sf __attribute__((CONST,CLONE,ARCH))
record(register const float solution,
		register const t_v3sf point,
		register const t_v3sf center,
		register const t_v3sf radius);
t_record_df __attribute__((CONST,CLONE,ARCH))
record(register const double solution,
		register const t_v3df point,
		register const t_v3df center,
		register const t_v3df radius);
t_record_sf __attribute__((CONST,CLONE,ARCH))
record(register const t_record_sf current_record);
t_record_df __attribute__((CONST,CLONE,ARCH))
record(const t_record_df current_record);
t_record_sf __attribute__((CONST,CLONE,ARCH))
record(register const float solution,
		register const t_v3sf point,
		register const t_v3sf normal);
t_record_df __attribute__((CONST,CLONE,ARCH))
record(register const double solution,
		register const t_v3df point,
		register const t_v3df normal);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
