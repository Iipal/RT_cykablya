/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:08:06 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:08:07 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORMALIZE_H
# define NORMALIZE_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "rsqroot.h"
#  include "vec_length_squared.h"
#  include "length_squared.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
normalize(register const t_v2sf x);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
normalize(register const t_v2df x);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
normalize(register const t_v3sf x);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
normalize(register const t_v3df x);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
normalize(register const t_v4sf x);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
normalize(register const t_v4df x);

# endif
#endif
