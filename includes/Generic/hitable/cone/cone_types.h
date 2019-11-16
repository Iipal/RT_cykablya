#ifndef CONE_TYPES_H
# define CONE_TYPES_H
# ifndef T_CONE_SF
#   define T_CONE_SF
#  ifndef VEC
#   define VEC(n) __ext_vector_type__(n),ALIGN
#  endif

typedef float	__attribute__((VEC(5)))	t_cone_sf;

#  ifdef VEC
#   undef VEC
#  endif
# endif
#endif
