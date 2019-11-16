/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_hit.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:23:15 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:23:16 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_HIT_H
# define CYLINDER_HIT_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
#  include "cylinder_center.h"
#  include "cylinder_top.h"
#  include "cylinder_radius.h"
#  include "cylinder_height.h"
#  include "cylinder_normal.h"
#  include "ray.h"
#  include "record.h"
#  include "solution.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
#  include "ray.h"
#  include "record.h"

t_record_sf __attribute__((CONST,CLONE,ARCH))
hit(register const t_cylinder_sf cyl,
		register const t_ray_sf ray,
		register const t_v2sf time,
		register const t_record_sf current_record);

# endif
#endif
