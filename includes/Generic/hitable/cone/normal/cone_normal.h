/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_normal.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:11:10 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:11:11 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_NORMAL_H
# define CONE_NORMAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
#  include "cone_center.h"
#  include "cone_radius.h"
#  include "cone_height.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_cone_sf cone,
		register const t_v3sf point);

# endif
#endif
