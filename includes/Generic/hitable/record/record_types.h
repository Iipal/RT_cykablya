#ifndef RECORD_TYPES_H
# define RECORD_TYPES_H

# if defined(__GNUC__) && defined(__clang__)
#  if !defined(RECORD_ATTR)
#   define RECORD_ATTR(n) (__ext_vector_type__(n),__aligned__(32))
#  endif
#  ifndef T_RECORD_SF
#   define T_RECORD_SF
typedef float __attribute__(RECORD_ATTR(8))			t_record_sf;
#  endif
#  ifndef T_RECORD_DF
#   define T_RECORD_DF
typedef double __attribute__(RECORD_ATTR(8))		t_record_df;
#  endif
#  if defined(RECORD_ATTR)
#   undef RECORD_ATTR
#  endif
# elif defined(__GNUC__) && !defined(__clang__)
#  if !defined(RECORD_ATTR)
#   define RECORD_ATTR(n, type) (__vector_size__(sizeof(type)*n),__aligned__)
#  endif
#  ifndef T_RECORD_SF
#   define T_RECORD_SF
typedef float __attribute__(RECORD_ATTR(8,float))	t_record_sf;
#  endif
#  ifndef T_RECORD_DF
#   define T_RECORD_DF
typedef double __attribute__(RECORD_ATTR(8,double))	t_record_df;
#  endif
#  if defined(RECORD_ATTR)
#   undef RECORD_ATTR
#  endif
# else
#  ifndef T_RECORD_SF
#   define T_RECORD_SF
typedef float										t_record_sf[8];
#  endif
#  ifndef T_RECORD_DF
#   define T_RECORD_DF
typedef double										t_record_df[8];
#  endif
# endif

#endif
