#ifndef VECTOR_TYPES_INTERNAL_H
# define VECTOR_TYPES_INTERNAL_H

# if defined(__GNUC__) && defined(__clang__)
#  ifndef C_VEC_ALIASED
#   define C_VEC_ALIASED(n) (__ext_vector_type__(n),__aligned__(1))
#  endif
#  ifndef T_V2SF_A
#   define T_V2SF_A

typedef float __attribute__(C_VEC_ALIASED(2))	t_v2sf_a;

#  endif
#  ifndef T_V3SF_A
#   define T_V3SF_A

typedef float __attribute__(C_VEC_ALIASED(3))	t_v3sf_a;

#  endif
#  ifndef T_V4SF_A
#   define T_V4SF_A

typedef float __attribute__(C_VEC_ALIASED(4))	t_v4sf_a;

#  endif
#  ifndef T_V8SF_A
#   define T_V8SF_A

typedef float __attribute__(C_VEC_ALIASED(8))	t_v8sf_a;

#  endif
#  ifndef T_V2DF_A
#   define T_V2DF_A

typedef double __attribute__(C_VEC_ALIASED(2))	t_v2df_a;

#  endif
#  ifndef T_V3DF_A
#   define T_V3DF_A

typedef double __attribute__(C_VEC_ALIASED(3))	t_v3df_a;

#  endif
#  ifndef T_V4DF_A
#   define T_V4DF_A

typedef double __attribute__(C_VEC_ALIASED(4))	t_v4df_a;

#  endif
#  if defined(C_VEC_ALIASED)
#   undef C_VEC_ALIASED
#  endif
# elif defined(__GNUC__) && !defined(__clang__)
#  if !defined(G_VEC_ALIASED)
#   define G_VEC_ALIASED(n,t) (__vector_size__(sizeof(t)*n),__aligned__(1),__may_alias__)
#  endif
#  ifndef T_V2SF_A
#   define T_V2SF_A

typedef float __attribute__(G_VEC_ALIASED(2,float))		t_v2sf_a;

#  endif
#  ifndef T_V3SF_A
#   define T_V3SF_A

typedef float __attribute__(G_VEC_ALIASED(4,float))		t_v3sf_a;

#  endif
#  ifndef T_V4SF_A
#   define T_V4SF_A

typedef float __attribute__(G_VEC_ALIASED(4,float))		t_v4sf_a;

#  endif
#  ifndef T_V8SF_A
#   define T_V8SF_A

typedef float __attribute__(G_VEC_ALIASED(8,float))		t_v8sf_a;

#  endif
#  ifndef T_V2DF_A
#   define T_V2DF_A

typedef double __attribute__(G_VEC_ALIASED(2,double))	t_v2df_a;

#  endif
#  ifndef T_V3DF_A
#   define T_V3DF_A

typedef double __attribute__(G_VEC_ALIASED(4,double))	t_v3df_a;

#  endif
#  ifndef T_V4DF_A
#   define T_V4DF_A

typedef double __attribute__(G_VEC_ALIASED(4,double))	t_v4df_a;

#  endif
#  if defined(G_VEC_ALIASED)
#   undef G_VEC_ALIASED
#  endif
# else
#  ifndef T_V2SF_A
#   define T_V2SF_A

typedef _Alignas(void) float 							t_v2sf_a[2];

#  endif
#  ifndef T_V3SF_A
#   define T_V3SF_A

typedef _Alignas(void) float							t_v3sf_a[3];

#  endif
#  ifndef T_V4SF_A
#   define T_V4SF_A

typedef _Alignas(void) float							t_v4sf_a[4];

#  endif
#  ifndef T_V8SF_A
#   define T_V8SF_A

typedef _Alignas(void) float							t_v8sf_a[8];

#  endif
#  ifndef T_V2DF_A
#   define T_V2DF_A

typedef _Alignas(void) double							t_v2df_a[2];

#  endif
#  ifndef T_V3DF_A
#   define T_V3DF_A

typedef _Alignas(void) double							t_v3df_a[3];

#  endif
#  ifndef T_V4DF_A
#   define T_V4DF_A

typedef _Alignas(void) double							t_v4df_a[4];

#  endif
# endif
#endif
