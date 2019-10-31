#ifndef VECTOR_INT_ALIASED_TYPES_H
# define VECTOR_INT_ALIASED_TYPES_H

# if defined(__GNUC__) && defined(__clang__)
#  ifndef C_VEC_ALIASED
#   define C_VEC_ALIASED(n) (__ext_vector_type__(n),__aligned__(1))
#  endif
#  ifndef T_V2SI_A
#   define T_V2SI_A

typedef int __attribute__(C_VEC_ALIASED(2))		t_v2si_a;

#  endif
#  ifndef T_V3SI_A
#   define T_V3SI_A

typedef int __attribute__(C_VEC_ALIASED(3))		t_v3si_a;

#  endif
#  ifndef T_V4SI_A
#   define T_V4SI_A

typedef int __attribute__(C_VEC_ALIASED(4))		t_v4si_a;

#  endif
#  ifndef T_V8SI_A
#   define T_V8SI_A

typedef int __attribute__(C_VEC_ALIASED(8))		t_v8si_a;

#  endif
#  ifndef T_V2DI_A
#   define T_V2DI_A

typedef long __attribute__(C_VEC_ALIASED(2))	t_v2di_a;

#  endif
#  ifndef T_V3DI_A
#   define T_V3DI_A

typedef long __attribute__(C_VEC_ALIASED(3))	t_v3di_a;

#  endif
#  ifndef T_V4DI_A
#   define T_V4DI_A

typedef long __attribute__(C_VEC_ALIASED(4))	t_v4di_a;

#  endif
#  if defined(C_VEC_ALIASED)
#   undef C_VEC_ALIASED
#  endif
# elif defined(__GNUC__) && !defined(__clang__)
#  if !defined(G_VEC_ALIASED)
#   define G_VEC_ALIASED(n,t) (__vector_size__(sizeof(t)*n),__aligned__(1),__may_alias__)
#  endif
#  ifndef T_V2SI_A
#   define T_V2SI_A

typedef int __attribute__(G_VEC_ALIASED(2,int))		t_v2si_a;

#  endif
#  ifndef T_V3SI_A
#   define T_V3SI_A

typedef int __attribute__(G_VEC_ALIASED(4,int))		t_v3si_a;

#  endif
#  ifndef T_V4SI_A
#   define T_V4SI_A

typedef int __attribute__(G_VEC_ALIASED(4,int))		t_v4si_a;

#  endif
#  ifndef T_V8SI_A
#   define T_V8SI_A

typedef int __attribute__(G_VEC_ALIASED(8,int))		t_v8si_a;

#  endif
#  ifndef T_V2DI_A
#   define T_V2DI_A

typedef long __attribute__(G_VEC_ALIASED(2,long))	t_v2di_a;

#  endif
#  ifndef T_V3DI_A
#   define T_V3DI_A

typedef long __attribute__(G_VEC_ALIASED(4,long))	t_v3di_a;

#  endif
#  ifndef T_V4DI_A
#   define T_V4DI_A

typedef long __attribute__(G_VEC_ALIASED(4,long))	t_v4di_a;

#  endif
#  if defined(G_VEC_ALIASED)
#   undef G_VEC_ALIASED
#  endif
# else
#  ifndef T_V2SI_A
#   define T_V2SI_A

typedef _Alignas(void) int 							t_v2si_a[2];

#  endif
#  ifndef T_V3SI_A
#   define T_V3SI_A

typedef _Alignas(void) int							t_v3si_a[3];

#  endif
#  ifndef T_V4SI_A
#   define T_V4SI_A

typedef _Alignas(void) int							t_v4si_a[4];

#  endif
#  ifndef T_V8SI_A
#   define T_V8SI_A

typedef _Alignas(void) int							t_v8si_a[8];

#  endif
#  ifndef T_V2DI_A
#   define T_V2DI_A

typedef _Alignas(void) long							t_v2di_a[2];

#  endif
#  ifndef T_V3DI_A
#   define T_V3DI_A

typedef _Alignas(void) long							t_v3di_a[3];

#  endif
#  ifndef T_V4DI_A
#   define T_V4DI_A

typedef _Alignas(void) long							t_v4di_a[4];

#  endif
# endif
#endif
