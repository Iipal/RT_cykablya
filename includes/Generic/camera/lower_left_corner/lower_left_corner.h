/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lower_left_corner.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:01:35 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:01:36 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOWER_LEFT_CORNER_H
# define LOWER_LEFT_CORNER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*lower_left_corner(void);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*lower_left_corner(register const float half_width,
						register const float half_height);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*lower_left_corner(register const t_v3sf vec);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
