/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_types.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:26:53 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:26:54 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TYPES_H
# define RAY_TYPES_H

# ifndef T_RAY_SF
#  define T_RAY_SF

typedef float __attribute__((__ext_vector_type__(6),__aligned__(32)))
t_ray_sf;
# endif
# ifndef T_RAY_DF
#  define T_RAY_DF

typedef double __attribute__((__ext_vector_type__(6),__aligned__(32)))
t_ray_df;
# endif

struct s_ray_sf;
struct s_ray_df;

#endif
