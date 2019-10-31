#ifndef SQROOT_H
# define SQROOT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"

extern float __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_sqrtf(register const float val);
extern double __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_sqrt(register const double val);
extern t_v3sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3sf_sqrtf(register const t_v3sf val);
extern t_v3df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v3df_sqrt(register const t_v3df val);
extern t_v4sf __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4sf_sqrtf(register const t_v4sf val);
extern t_v4df __attribute__((CONST,ALIGN,SMALL_STACK,ARCH))
asm_v4df_sqrt(register const t_v4df val);

# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const float val);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const double val);
t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v2sf vec);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v2df vec);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v3sf vec);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v3df vec);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v4sf vec);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v4df vec);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
