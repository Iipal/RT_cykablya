#ifndef PLANE_TYPES_H
# define PLANE_TYPES_H
# ifndef T_PLANE_SF
#  define T_PLANE_SF
#  ifndef VEC
#   define VEC(n) __ext_vector_type__(n),ALIGN
#  endif

typedef float	__attribute__((VEC(12)))	t_plane_sf;

#  ifdef VEC
#   undef VEC
#  endif
# endif
#endif
