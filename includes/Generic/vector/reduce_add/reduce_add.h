/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reduce_add.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:09:04 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:09:05 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REDUCE_ADD_H
# define REDUCE_ADD_H
# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "asm_reduce_add.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v2sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v2df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v3sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v3df vec);
float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v4sf vec);
double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
reduce_add(register const t_v4df vec);

# endif
#endif
