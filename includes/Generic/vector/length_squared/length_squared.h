/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_squared.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:07:57 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:07:58 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LENGTH_SQUARED_H
# define LENGTH_SQUARED_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "dot.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v2sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v2df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v3sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v3df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v4sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
length_squared(register const t_v4df vec);

# endif
#endif
