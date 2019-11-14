#ifndef RAY_TYPES_H
# define RAY_TYPES_H

# ifndef T_RAY_SF
#  define T_RAY_SF
typedef float __attribute__((__ext_vector_type__(8),__aligned__(32)))	t_ray_sf;
# endif
# ifndef T_RAY_DF
#  define T_RAY_DF
typedef double __attribute__((__ext_vector_type__(8),__aligned__(32)))	t_ray_df;
# endif

struct																	s_ray_sf;
struct																	s_ray_df;

#endif

