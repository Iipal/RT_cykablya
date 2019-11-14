#ifndef VECTOR_TYPES_H
# define VECTOR_TYPES_H
# ifndef C_VEC
#  define C_VEC(n) (__ext_vector_type__(n),__aligned__)
# endif
# ifndef T_V2SF
#  define T_V2SF

typedef float __attribute__(C_VEC(2))	t_v2sf;

# endif
# ifndef T_V3SF
#  define T_V3SF

typedef float __attribute__(C_VEC(3))	t_v3sf;

# endif
# ifndef T_V4SF
#  define T_V4SF

typedef float __attribute__(C_VEC(4))	t_v4sf;

# endif
# ifndef T_V8SF
#  define T_V8SF

typedef float __attribute__(C_VEC(8))	t_v8sf;

# endif
# ifndef T_V2DF
#  define T_V2DF

typedef double __attribute__(C_VEC(2))	t_v2df;

# endif
# ifndef T_V3DF
#  define T_V3DF

typedef double __attribute__(C_VEC(3))	t_v3df;

# endif
# ifndef T_V4DF
#  define T_V4DF

typedef double __attribute__(C_VEC(4))	t_v4df;

# endif
# if defined(C_VEC)
#  undef C_VEC
# endif
#endif
