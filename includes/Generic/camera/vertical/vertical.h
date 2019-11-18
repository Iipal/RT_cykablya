/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:06:16 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:06:17 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VERTICAL_H
# define VERTICAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*vertical(void);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*vertical(register const float half_height);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*vertical(register const t_v3sf vec);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
