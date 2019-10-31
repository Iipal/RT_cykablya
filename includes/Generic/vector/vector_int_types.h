#ifndef VECTOR_INT_TYPES_H
# define VECTOR_INT_TYPES_H

# if defined(__GNUC__) && defined(__clang__)
#  ifndef C_VEC_ALIASED
#   define C_VEC_ALIASED(n) (__ext_vector_type__(n),__aligned__)
#  endif
#  ifndef T_V2SI
#   define T_V2SI

typedef int __attribute__(C_VEC_ALIASED(2))		t_v2si;

#  endif
#  ifndef T_V3SI
#   define T_V3SI

typedef int __attribute__(C_VEC_ALIASED(3))		t_v3si;

#  endif
#  ifndef T_V4SI
#   define T_V4SI

typedef int __attribute__(C_VEC_ALIASED(4))		t_v4si;

#  endif
#  ifndef T_V8SI
#   define T_V8SI

typedef int __attribute__(C_VEC_ALIASED(8))		t_v8si;

#  endif
#  ifndef T_V2DI
#   define T_V2DI

typedef long __attribute__(C_VEC_ALIASED(2))	t_v2di;

#  endif
#  ifndef T_V3DI
#   define T_V3DI

typedef long __attribute__(C_VEC_ALIASED(3))	t_v3di;

#  endif
#  ifndef T_V4DI
#   define T_V4DI

typedef long __attribute__(C_VEC_ALIASED(4))	t_v4di;

#  endif
#  if defined(C_VEC_ALIASED)
#   undef C_VEC_ALIASED
#  endif
# elif defined(__GNUC__) && !defined(__clang__)
#  if !defined(G_VEC_ALIASED)
#   define G_VEC_ALIASED(n,t) (__vector_size__(sizeof(t)*n),__aligned__)
#  endif
#  ifndef T_V2SI
#   define T_V2SI

typedef int __attribute__(G_VEC_ALIASED(2,int))		t_v2si;

#  endif
#  ifndef T_V3SI
#   define T_V3SI

typedef int __attribute__(G_VEC_ALIASED(4,int))		t_v3si;

#  endif
#  ifndef T_V4SI
#   define T_V4SI

typedef int __attribute__(G_VEC_ALIASED(4,int))		t_v4si;

#  endif
#  ifndef T_V8SI
#   define T_V8SI

typedef int __attribute__(G_VEC_ALIASED(8,int))		t_v8si;

#  endif
#  ifndef T_V2DI
#   define T_V2DI

typedef long __attribute__(G_VEC_ALIASED(2,long))	t_v2di;

#  endif
#  ifndef T_V3DI
#   define T_V3DI

typedef long __attribute__(G_VEC_ALIASED(4,long))	t_v3di;

#  endif
#  ifndef T_V4DI
#   define T_V4DI

typedef long __attribute__(G_VEC_ALIASED(4,long))	t_v4di;

#  endif
#  if defined(G_VEC_ALIASED)
#   undef G_VEC_ALIASED
#  endif
# else
#  ifndef T_V2SI
#   define T_V2SI

typedef _Alignas(void) int 							t_v2si[2];

#  endif
#  ifndef T_V3SI
#   define T_V3SI

typedef _Alignas(void) int							t_v3si[3];

#  endif
#  ifndef T_V4SI
#   define T_V4SI

typedef _Alignas(void) int							t_v4si[4];

#  endif
#  ifndef T_V8SI
#   define T_V8SI

typedef _Alignas(void) int							t_v8si[8];

#  endif
#  ifndef T_V2DI
#   define T_V2DI

typedef _Alignas(void) long							t_v2di[2];

#  endif
#  ifndef T_V3DI
#   define T_V3DI

typedef _Alignas(void) long							t_v3di[3];

#  endif
#  ifndef T_V4DI
#   define T_V4DI

typedef _Alignas(void) long							t_v4di[4];

#  endif
# endif
#endif
