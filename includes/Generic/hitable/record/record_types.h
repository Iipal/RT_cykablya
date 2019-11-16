#ifndef RECORD_TYPES_H
# define RECORD_TYPES_H
# if !defined(RECORD_ATTR)
#  define RECORD_ATTR(n) (__ext_vector_type__(n),__aligned__(32))
# endif
# ifndef T_RECORD_SF
#  define T_RECORD_SF

typedef float __attribute__(RECORD_ATTR(8))			t_record_sf;

# endif
# ifndef T_RECORD_DF
#  define T_RECORD_DF

typedef double __attribute__(RECORD_ATTR(8))		t_record_df;

# endif
# if defined(RECORD_ATTR)
#  undef RECORD_ATTR
# endif
#endif
