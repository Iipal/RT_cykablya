#ifndef SPHERE_TYPES_H
# define SPHERE_TYPES_H

# ifndef S_SPHERE_SF
#  define S_SPHERE_SF
struct												s_sphere_sf;
# endif
# ifndef S_SPHERE_DF
#  define S_SPHERE_DF
struct												s_sphere_df;
# endif

# if defined(__GNUC__) && defined(__clang__)
#  if !defined(SPHERE_ATTR)
#   define SPHERE_ATTR(n) (__ext_vector_type__(n),__aligned__(32))
#  endif
#  ifndef T_SPHERE_SF
#   define T_SPHERE_SF
typedef float __attribute__(SPHERE_ATTR(6))			t_sphere_sf;
#  endif
#  ifndef T_SPHERE_DF
#   define T_SPHERE_DF
typedef double __attribute__(SPHERE_ATTR(6))		t_sphere_df;
#  endif
#  if defined(SPHERE_ATTR)
#   undef SPHERE_ATTR
#  endif
# elif defined(__GNUC__) && !defined(__clang__)
#  if !defined(SPHERE_ATTR)
#   define SPHERE_ATTR(n, type) (__vector_size__(sizeof(type)*n),__aligned__)
#  endif
#  ifndef T_SPHERE_SF
#   define T_SPHERE_SF
typedef float __attribute__(SPHERE_ATTR(8,float))	t_sphere_sf;
#  endif
#  ifndef T_SPHERE_DF
#   define T_SPHERE_DF
typedef double __attribute__(SPHERE_ATTR(8,double))	t_sphere_df;
#  endif
# else
#  ifndef T_SPHERE_SF
#   define T_SPHERE_SF
typedef float										t_sphere_sf[6];
#  endif
#  ifndef T_SPHERE_DF
#   define T_SPHERE_DF
typedef double										t_sphere_sf[6];
#  endif
#  if defined(SPHERE_ATTR)
#   undef SPHERE_ATTR
#  endif
# endif

#endif
