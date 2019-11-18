/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_constructor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:03:15 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:03:16 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_CONSTRUCTOR_H
# define VECTOR_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "vector_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec(register const float e_0,
	register const float e_1);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec(register const double e_0,
	register const double e_1);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec(register const float e_0,
	register const float e_1,
	register const float e_2);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec(register const double e_0,
	register const double e_1,
	register const double e_2);
t_v3sf __attribute__((PURE,CLONE,SMALL_STACK,ARCH))
vec(const float e[static 3]);
t_v3df __attribute__((PURE,CLONE,SMALL_STACK,ARCH))
vec(const double e[static 3]);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec(register const float e_0,
	register const float e_1,
	register const float e_2,
	register const float e_3);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
vec(register const double e_0,
	register const double e_1,
	register const double e_2,
	register const double e_3);

# endif
#endif
