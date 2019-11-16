/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_to_rgb.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:31:15 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 22:31:16 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_TO_RGB_H
# define COLOR_TO_RGB_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "vector_types.h"
#  include "asm_color_to_rgb.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

unsigned __attribute__((CONST,SMALL_STACK,ARCH))
color_to_rgb(register const t_v3sf col);

# endif
#endif
