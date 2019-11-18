/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:17:10 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/17 00:17:11 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_TYPES_H
# define PLANE_TYPES_H
# ifndef T_PLANE_SF
#  define T_PLANE_SF
#  ifndef VEC
#   define VEC(n) __ext_vector_type__(n),ALIGN
#  endif

typedef float __attribute__((VEC(12)))	t_plane_sf;

#  ifdef VEC
#   undef VEC
#  endif
# endif
#endif
