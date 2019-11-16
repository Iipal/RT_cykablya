/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_hit.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:17:14 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:17:16 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONE_HIT_H
# define CONE_HIT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
#  include "cone_center.h"
#  include "cone_radius.h"
#  include "cone_height.h"
#  include "cone_normal.h"
#  include "record.h"
#  include "ray.h"
#  include "solution.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cone_types.h"
#  include "record.h"
#  include "ray.h"

t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_cone_sf cone,
	register const t_ray_sf ray,
	register const t_v2sf time,
	register const t_record_sf current_record);

# endif
#endif
