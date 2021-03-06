/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_types_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:15:19 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/17 00:15:20 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_TYPES_INTERNAL_H
# define RECORD_TYPES_INTERNAL_H

# include <stdint.h>
# include "record_types.h"
# include "vector_types_internal.h"

# if defined(__GNUC__) && defined(__clang__)
#  if !defined(RECORD_ATTR)
#   define RECORD_MASK_ATTR(n) __ext_vector_type__(n),__aligned__(32)
#  endif
#  ifndef T_RECORD_MASK_SI
#   define T_RECORD_MASK_SI

typedef char __attribute__((RECORD_MASK_ATTR(32)))	t_record_mask_si;

#  endif
#  ifndef T_RECORD_MASK_DI
#   define T_RECORD_MASK_DI

typedef char __attribute__((RECORD_MASK_ATTR(64)))	t_record_mask_di;

#  endif
#  ifndef T_RECORD_MASK_HI
#   define T_RECORD_MASK_HI

typedef short int __attribute__((RECORD_MASK_ATTR(16)))	t_record_mask_hi;

#  endif
#  ifndef T_RECORD_MASK_QI
#   define T_RECORD_MASK_QI

typedef char __attribute__((RECORD_MASK_ATTR(32)))	t_record_mask_qi;

#  endif
#  if defined(RECORD_MASK_ATTR)
#   undef RECORD_MASK_ATTR
#  endif
# endif

# ifndef U_RECORD_HELPER
#  define U_RECORD_HELPER

union	u_record_helper
{
	t_record_sf			sf;
	t_record_mask_qi	qi;
	t_record_mask_hi	hi;
} __attribute__((__aligned__(32)));

# endif
# ifndef S_POINT_HELPER_SF
#  define S_POINT_HELPER_SF

struct	s_point_helper_sf
{
	float	stub[3];
};

# endif
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
