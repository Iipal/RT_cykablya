#ifndef RADIUS_H
# define RADIUS_H

# ifdef IMPLEMETNATION
#  include "sphere_types_internal.h"
# endif

# ifdef DECLARATION

# include "sphere_types.h"
# include "vector_types.h"

t_v3sf __attribute__((__overloadable__))
radius(const t_sphere_sf s);
t_v3df __attribute__((__overloadable__))
radius(const t_sphere_df s);
t_v3sf __attribute__((__overloadable__))
radius(const struct s_sphere_sf *const restrict s);
t_v3df __attribute__((__overloadable__))
radius(const struct s_sphere_df *const restrict s);

# endif

#endif
