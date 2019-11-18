/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_types_internal.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:59:19 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 22:59:20 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_TYPES_INTERNAL_H
# define SPHERE_TYPES_INTERNAL_H
# include "sphere_types.h"
# include "vector_types.h"

# ifndef S_SPHERE_SF
#  define S_SPHERE_SF

struct		s_sphere_sf
{
	t_v3sf	center;
	t_v3sf	radius;
};

# endif
# ifndef S_SPHERE_DF
#  define S_SPHERE_DF

struct		s_sphere_df
{
	t_v3df	center;
	t_v3df	radius;
};

# endif
#endif
