#ifndef VECTOR_INT_TYPES_H
# define VECTOR_INT_TYPES_H
# ifndef C_VEC
#  define C_VEC(n) (__ext_vector_type__(n),__aligned__)
# endif
# ifndef T_V2SI
#  define T_V2SI

typedef int __attribute__(C_VEC(2))		t_v2si;

# endif
# ifndef T_V3SI
#  define T_V3SI

typedef int __attribute__(C_VEC(3))		t_v3si;

# endif
# ifndef T_V4SI
#  define T_V4SI

typedef int __attribute__(C_VEC(4))		t_v4si;

# endif
# ifndef T_V8SI
#  define T_V8SI

typedef int __attribute__(C_VEC(8))		t_v8si;

# endif
# ifndef T_V2DI
#  define T_V2DI

typedef long __attribute__(C_VEC(2))	t_v2di;

# endif
# ifndef T_V3DI
#  define T_V3DI

typedef long __attribute__(C_VEC(3))	t_v3di;

# endif
# ifndef T_V4DI
#  define T_V4DI

typedef long __attribute__(C_VEC(4))	t_v4di;

# endif
# if defined(C_VEC)
#  undef C_VEC
# endif
#endif
