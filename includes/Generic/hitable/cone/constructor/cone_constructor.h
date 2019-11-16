/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_constructor.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:14:49 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:14:51 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_CONSTRUCTOR_H
# define CONE_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"

t_cone_sf __attribute__((CONST,CLONE,ARCH))
cone(register const t_v3sf center,
	register const float radius,
	register const float height);

# endif
#endif
