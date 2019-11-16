/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_color_to_rgb.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:41:00 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 22:41:05 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_COLOR_TO_RGB_H
# define ASM_COLOR_TO_RGB_H

# ifndef T_V3SU
#  define T_V3SU
#  ifndef VEC
#   define VEC(n) __attribute__((__ext_vector_type__(n),__aligned__))
#  endif

typedef	unsigned int __attribute__((VEC(3)))	t_v3su;

#  ifdef VEC
#   undef VEC
#  endif
# endif
#endif
