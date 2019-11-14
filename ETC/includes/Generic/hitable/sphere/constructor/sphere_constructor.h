#ifndef SPHERE_CONSTRUCTOR_H
# define SPHERE_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "sphere_types_internal.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
# endif

# ifdef DECLARATION

# include "sphere_types.h"
# include "vector_types.h"

t_sphere_sf __attribute__((__overloadable__,__target__("avx")))
sphere(register const t_v3sf center, register const t_v3sf radius);
t_sphere_sf __attribute__((__overloadable__,__target__("avx")))
sphere(register const t_v3sf center, register const float radius);
t_sphere_df __attribute__((__overloadable__,__target__("avx")))
sphere(register const t_v3df center, register const t_v3df radius);
t_sphere_df __attribute__((__overloadable__,__target__("avx")))
sphere(register const t_v3df center, register const double radius);
struct s_sphere_sf __attribute__((__overloadable__))
*sphere(void);
struct s_sphere_sf __attribute__((__overloadable__))
*sphere(const float f);
struct s_sphere_df __attribute__((__overloadable__))
*sphere(const double f);

# endif

#endif
