#ifndef SPHERE_TYPES_INTERNAL_H
# define SPHERE_TYPES_INTERNAL_H
# include "sphere_types.h"
# include "vector_types.h"

# ifndef S_SPHERE_SF
#  define S_SPHERE_SF

struct		s_sphere_sf
{
	t_v3sf	center;
	t_v3sf	radius;
};

# endif
# ifndef S_SPHERE_DF
#  define S_SPHERE_DF

struct		s_sphere_df
{
	t_v3df	center;
	t_v3df	radius;
};

# endif
#endif
