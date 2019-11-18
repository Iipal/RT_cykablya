/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rsqroot.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:11:30 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:11:31 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RSQROOT_H
# define RSQROOT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "sqroot.h"
#  include "asm_rsqroot.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const float x);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const double x);
t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const t_v2sf x);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const t_v2df x);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const t_v3sf x);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const t_v3df x);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const t_v4sf x);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
rsqroot(register const t_v4df x);

# endif
#endif
