/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:10:11 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 22:10:12 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REFRACT_H
# define REFRACT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract(register const t_v2sf x,
		register const t_v2sf n,
		register const float eta);
t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract(register const t_v2df x,
		register const t_v2df n,
		register const double eta);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract(register const t_v3sf x,
		register const t_v3sf n,
		register const float eta);
t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract(register const t_v3df x,
		register const t_v3df n,
		register const double eta);
t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract(register const t_v4sf x,
		register const t_v4sf n,
		register const float eta);
t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
refract(register const t_v4df x,
		register const t_v4df n,
		register const double eta);

# endif
#endif
