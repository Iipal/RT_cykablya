/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:09:56 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:09:57 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFLECT_H
# define REFLECT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vec_dot.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reflect(register const t_v2sf x, register const t_v2sf n);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reflect(register const t_v2df x, register const t_v2df n);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reflect(register const t_v3sf x, register const t_v3sf n);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reflect(register const t_v3df x, register const t_v3df n);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reflect(register const t_v4sf x, register const t_v4sf n);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reflect(register const t_v4df x, register const t_v4df n);

# endif
#endif
