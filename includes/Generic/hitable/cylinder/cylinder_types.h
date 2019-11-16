#ifndef CYLINDER_TYPES_H
# define CYLINDER_TYPES_H
# ifndef T_CYLINDER_SF
#  define T_CYLINDER_SF
#  ifndef VEC
#   define VEC(n) __ext_vector_type__(n),ALIGN
#  endif

typedef float	__attribute__((VEC(7)))	t_cylinder_sf;

#  ifdef VEC
#   undef VEC
#  endif
# endif
#endif
