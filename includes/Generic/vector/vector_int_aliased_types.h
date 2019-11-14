#ifndef VECTOR_INT_ALIASED_TYPES_H
# define VECTOR_INT_ALIASED_TYPES_H

# ifndef C_VEC_ALIASED
#  define C_VEC_ALIASED(n) (__ext_vector_type__(n),__aligned__(1))
# endif
# ifndef T_V2SI_A
#  define T_V2SI_A

typedef int __attribute__(C_VEC_ALIASED(2))		t_v2si_a;

# endif
# ifndef T_V3SI_A
#  define T_V3SI_A

typedef int __attribute__(C_VEC_ALIASED(3))		t_v3si_a;

# endif
# ifndef T_V4SI_A
#  define T_V4SI_A

typedef int __attribute__(C_VEC_ALIASED(4))		t_v4si_a;

# endif
# ifndef T_V8SI_A
#  define T_V8SI_A

typedef int __attribute__(C_VEC_ALIASED(8))		t_v8si_a;

# endif
# ifndef T_V2DI_A
#  define T_V2DI_A

typedef long __attribute__(C_VEC_ALIASED(2))	t_v2di_a;

# endif
# ifndef T_V3DI_A
#  define T_V3DI_A

typedef long __attribute__(C_VEC_ALIASED(3))	t_v3di_a;

# endif
# ifndef T_V4DI_A
#  define T_V4DI_A

typedef long __attribute__(C_VEC_ALIASED(4))	t_v4di_a;

# endif
# if defined(C_VEC_ALIASED)
#  undef C_VEC_ALIASED
# endif
#endif
