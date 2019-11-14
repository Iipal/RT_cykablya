#ifndef RECORD_TYPES_INTERNAL_H
# define RECORD_TYPES_INTERNAL_H

# include <stdint.h>
# include "record_types.h"
# include "vector_types_internal.h"

# if defined(__GNUC__) && defined(__clang__)
#  if !defined(RECORD_ATTR)
#   define RECORD_MASK_ATTR(n) (__ext_vector_type__(n),__aligned__(32))
#  endif
#  ifndef T_RECORD_MASK_SI
#   define T_RECORD_MASK_SI
typedef char __attribute__(RECORD_MASK_ATTR(32))	t_record_mask_si;
#  endif
#  ifndef T_RECORD_MASK_DI
#   define T_RECORD_MASK_DI
typedef char __attribute__(RECORD_MASK_ATTR(64))	t_record_mask_di;
#  endif
#  ifndef T_RECORD_MASK_HI
#   define T_RECORD_MASK_HI
typedef short __attribute__(RECORD_MASK_ATTR(16))	t_record_mask_hi;
#  endif
#  ifndef T_RECORD_MASK_QI
#   define T_RECORD_MASK_QI
typedef char __attribute__(RECORD_MASK_ATTR(32))	t_record_mask_qi;
#  endif
#  if defined(RECORD_MASK_ATTR)
#   undef RECORD_MASK_ATTR
#  endif
# elif defined(__GNUC__) && !defined(__clang__)
#  if !defined(RECORD_MASK_ATTR)
#   define RECORD_MASK_ATTR(n, type) (__vector_size__(sizeof(type)),__aligned__)
#  endif
#  ifndef T_RECORD_MASK_SI
#   define T_RECORD_MASK_SI
typedef char __attribute__(RECORD_MASK_ATTR(t_record_sf))	t_record_mask_si;
#  endif
#  ifndef T_RECORD_MASK_DI
#   define T_RECORD_MASK_DI
typedef long __attribute__(RECORD_MASK_ATTR(t_record_df))	t_record_mask_di;
#  endif
#  if defined(RECORD_MASK_ATTR)
#   undef RECORD_MASK_ATTR
#  endif
# else
#  ifndef T_RECORD_MASK_SI
#   define T_RECORD_MASK_SI
typedef char												t_record_mask_si[32];
#  endif
#  ifndef T_RECORD_MASK_DI
#   define T_RECORD_MASK_DI
typedef char												t_hit_record_df[64];
#  endif
# endif

struct	s_point_helper_sf
{
	float	stub[3];
};

# ifndef S_RECORD_SF
#  define S_RECORD_SF
struct	s_record_sf
{
	_Bool		condition;
	uint8_t		material;
	uint16_t	i;
	float		solution;
	float		point[3];
	float		normal[3];
} __attribute__((__aligned__(32)));
# endif
# ifndef U_RECORD_SF
#  define U_RECORD_SF
union	u_record_sf
{
	t_record_sf			vec;
	struct s_record_sf	str;
} __attribute__((__aligned__(32)));
# endif
# ifndef S_RECORD_DF
#  define S_RECORD_DF
struct	s_record_df
{
	_Bool		condition;
	uint8_t		material;
	uint8_t		unused[6];
	double		solution;
	double		point[3];
	double		normal[3];
};
# endif
# ifndef U_RECORD_DF
#  define U_RECORD_DF
union	u_record_df
{
	t_record_df			vec;
	struct s_record_df	str;
};
# endif
#endif
