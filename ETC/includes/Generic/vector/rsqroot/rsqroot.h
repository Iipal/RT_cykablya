#ifndef RSQROOT_H
# define RSQROOT_H

# ifdef IMPLEMETNATION
#  include "sqroot.h"

extern t_v2sf __attribute__((__const__,__aligned__,__target__("avx,fma"),__no_split_stack__))
asm_v2sf_rsqroot(register const t_v2sf vec);
extern t_v3sf __attribute__((__const__,__aligned__,__target__("avx,fma"),__no_split_stack__))
asm_v3sf_rsqroot(register const t_v3sf vec);
extern t_v4sf __attribute__((__const__,__aligned__,__target__("avx,fma"),__no_split_stack__))
asm_v4sf_rsqroot(register const t_v4sf vec);

# endif

# ifdef DECLARATION
#  include "vector_types.h"

float __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const float x);
double __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const double x);
t_v2sf __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const t_v2sf x);
t_v2df __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const t_v2df x);
t_v3sf __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const t_v3sf x);
t_v3df __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const t_v3df x);
t_v4sf __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const t_v4sf x);
t_v4df __attribute__((__overloadable__,__const__,__aligned__,__target__("avx"),__no_split_stack__))
rsqroot(register const t_v4df x);

# endif
#endif
