#ifndef REDUCE_ADD_H
# define REDUCE_ADD_H
# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"

extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v2sf(register const t_v2sf vec);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v2df(register const t_v2df vec);
extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v3sf(register const t_v3sf vec);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v3df(register const t_v3df vec);
extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v4sf(register const t_v4sf vec);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_reduce_add_v4df(register const t_v4df vec);

# endif

# ifdef DECLARATION
#  include "attributes.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v2sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v2df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v3sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v3df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v4sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v4df vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
