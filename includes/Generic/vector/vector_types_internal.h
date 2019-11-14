#ifndef VECTOR_TYPES_INTERNAL_H
# define VECTOR_TYPES_INTERNAL_H
# ifndef C_VEC_ALIASED
#  define C_VEC_ALIASED(n) (__ext_vector_type__(n),__aligned__(1))
# endif
# ifndef T_V2SF_A
#  define T_V2SF_A

typedef float __attribute__(C_VEC_ALIASED(2))	t_v2sf_a;

# endif
# ifndef T_V3SF_A
#  define T_V3SF_A

typedef float __attribute__(C_VEC_ALIASED(3))	t_v3sf_a;

# endif
# ifndef T_V4SF_A
#  define T_V4SF_A

typedef float __attribute__(C_VEC_ALIASED(4))	t_v4sf_a;

# endif
# ifndef T_V8SF_A
#  define T_V8SF_A

typedef float __attribute__(C_VEC_ALIASED(8))	t_v8sf_a;

# endif
# ifndef T_V2DF_A
#  define T_V2DF_A

typedef double __attribute__(C_VEC_ALIASED(2))	t_v2df_a;

# endif
# ifndef T_V3DF_A
#  define T_V3DF_A

typedef double __attribute__(C_VEC_ALIASED(3))	t_v3df_a;

# endif
# ifndef T_V4DF_A
#  define T_V4DF_A

typedef double __attribute__(C_VEC_ALIASED(4))	t_v4df_a;

# endif
# if defined(C_VEC_ALIASED)
#  undef C_VEC_ALIASED
# endif
#endif
