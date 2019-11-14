/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_types_internal.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:29:21 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:29:26 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TYPES_INTERNAL_H
# define RAY_TYPES_INTERNAL_H

# include "vector_types.h"
# include "ray_types.h"
# define VEC_ALIAS(n) __ext_vector_type__(n),__aligned__(1)

# ifndef T_RAY_SF_A
#  define T_RAY_SF_A

typedef float __attribute__((VEC_ALIAS(6)))							t_ray_sf_a;

# endif
# ifndef T_RAY_DF_A
#  define T_RAY_DF_A

typedef double __attribute__((VEC_ALIAS(6)))						t_ray_df_a;

# endif

# ifndef U_RAY_SF
#  define U_RAY_SF

union																u_ray_sf
{
	t_ray_sf_a	aliased;
	t_ray_sf	aligned;
};

# endif
# ifndef U_RAY_DF
#  define U_RAY_DF

union																u_ray_df
{
	t_ray_df_a	aliased;
	t_ray_df	aligned;
};

# endif
# ifndef S_RAY_SF
#  define S_RAY_SF

struct																s_ray_sf
{
	t_v3sf	a;
	t_v3sf	b;
};

# endif
# ifndef S_RAY_DF
#  define S_RAY_DF

struct																s_ray_df
{
	t_v3df	a;
	t_v3df	b;
};

# endif
#endif
