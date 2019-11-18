/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sqroot.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:11:59 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:12:00 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SQROOT_H
# define SQROOT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "asm_sqroot.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const float val);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const double val);
t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v2sf vec);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v2df vec);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v3sf vec);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v3df vec);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v4sf vec);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
sqroot(register const t_v4df vec);

# endif
#endif
