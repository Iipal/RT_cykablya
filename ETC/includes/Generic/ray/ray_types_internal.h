#ifndef RAY_TYPES_INTERNAL_H
# define RAY_TYPES_INTERNAL_H

# include "vector_types.h"
# include "ray_types.h"

# ifndef T_RAY_SF_A
#  define T_RAY_SF_A
typedef float __attribute__((__ext_vector_type__(6),__aligned__(1)))	t_ray_sf_a;
# endif

# ifndef T_RAY_DF_A
#  define T_RAY_DF_A
typedef double __attribute__((__ext_vector_type__(6),__aligned__(1)))	t_ray_df_a;
# endif

# ifndef U_RAY_SF
#  define U_RAY_SF
union																	u_ray_sf
{
	t_ray_sf_a	aliased;
	t_ray_sf	aligned;
};
# endif

# ifndef U_RAY_DF
#  define U_RAY_DF
union																	u_ray_df
{
	t_ray_df_a	aliased;
	t_ray_df	aligned;
};
# endif

# ifndef S_RAY_SF
#  define S_RAY_SF
struct																	s_ray_sf
{
	t_v3sf	a;
	t_v3sf	b;
};
# endif

# ifndef S_RAY_DF
#  define S_RAY_DF
struct																	s_ray_df
{
	t_v3df	a;
	t_v3df	b;
};
# endif
#endif
