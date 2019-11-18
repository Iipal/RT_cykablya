/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:04:47 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:04:48 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CROSS_H
# define CROSS_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v2sf x, register const t_v2sf y);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v2df x, register const t_v2df y);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v3sf x, register const t_v3sf y);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
cross(register const t_v3df x, register const t_v3df y);

# endif
#endif
