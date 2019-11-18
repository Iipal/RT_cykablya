/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_reduce_add.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:25:32 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:25:33 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_REDUCE_ADD_H
# define VEC_REDUCE_ADD_H
# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "asm_vec_reduce_add.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v2sf vec);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v2df vec);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v3sf vec);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v3df vec);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v4sf vec);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec_reduce_add(register const t_v4df vec);

# endif
#endif
