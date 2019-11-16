/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_types.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 00:17:49 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/17 00:17:50 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_TYPES_H
# define CYLINDER_TYPES_H
# ifndef T_CYLINDER_SF
#  define T_CYLINDER_SF
#  ifndef VEC
#   define VEC(n) __ext_vector_type__(n),ALIGN
#  endif

typedef float __attribute__((VEC(7)))	t_cylinder_sf;

#  ifdef VEC
#   undef VEC
#  endif
# endif
#endif
