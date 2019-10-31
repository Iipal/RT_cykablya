#ifndef SCENE_GENERATOR_H
# define SCENE_GENERATOR_H

# ifdef IMPLEMETNATION
#  include <stddef.h>
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
#  include "attributes.h"
#  include "vector.h"
#  include "hitable.h"
#  include "random_float.h"
#  include "material.h"
#  include "hitable_types.h"
#  include "hitable_types_internal.h"
#  include "vector_types.h"
# endif

union u_hitables __attribute__((ALIGN,ARCH))
*scene_generator(register const size_t count);

# ifdef DECLARATION
#  include <stddef.h>
#  include "attributes.h"
#  include "hitable_types.h"
#  include "vector_types.h"

union u_hitables __attribute__((ALIGN,ARCH))
*scene_generator(register const size_t count);

#  ifndef IMPLEMETNATION
#   include "free_attributes.h"
#  endif
# endif
#endif
