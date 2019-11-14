/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:00:46 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:00:49 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HORIZONTAL_H
# define HORIZONTAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*horizontal(void);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*horizontal(register const float half_width);
t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
*horizontal(register const t_v3sf vec);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
