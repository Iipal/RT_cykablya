#ifndef VEC_REDUCE_ADD_H
# define VEC_REDUCE_ADD_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"

extern t_v2sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v2sf_reduce_add(register const t_v2sf vec);
extern t_v2df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v2df_reduce_add(register const t_v2df vec);
extern t_v3sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3sf_reduce_add(register const t_v3sf vec);
extern t_v3df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3df_reduce_add(register const t_v3df vec);
extern t_v4sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4sf_reduce_add(register const t_v4sf vec);
extern t_v4df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4df_reduce_add(register const t_v4df vec);

# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v2sf vec);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v2df vec);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v3sf vec);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v3df vec);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v4sf vec);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v4df vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
