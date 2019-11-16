/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_types.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:25:31 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/17 00:05:38 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAHEDRON_TYPES_H
# define TETRAHEDRON_TYPES_H

# ifndef T_TETRAHEDRON_SF
#  define T_TETRAHEDRON_SF
#  ifndef VEC
#   define VEC(n) __ext_vector_type__(n),ALIGN
#  endif

typedef float __attribute__((VEC(9)))	t_tetrahedron_sf;

#  ifdef VEC
#   undef VEC
#  endif
# endif
#endif
