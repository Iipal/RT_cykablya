/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_types.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:14:59 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/17 00:15:01 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_TYPES_H
# define SPHERE_TYPES_H

struct s_sphere_sf;
struct s_sphere_df;

# if !defined(SPHERE_ATTR)
#  define SPHERE_ATTR(n) __ext_vector_type__(n),__aligned__(32)
# endif
# ifndef T_SPHERE_SF
#  define T_SPHERE_SF

typedef float __attribute__((SPHERE_ATTR(6)))			t_sphere_sf;

# endif
# ifndef T_SPHERE_DF
#  define T_SPHERE_DF

typedef double __attribute__((SPHERE_ATTR(6)))		t_sphere_df;

# endif
# if defined(SPHERE_ATTR)
#  undef SPHERE_ATTR
# endif
#endif
