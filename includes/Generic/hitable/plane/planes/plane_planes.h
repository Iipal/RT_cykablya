/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_planes.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:07:56 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:07:57 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_PLANES_H
# define PLANE_PLANES_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_a(register const t_plane_sf plane);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_b(register const t_plane_sf plane);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_c(register const t_plane_sf plane);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_d(register const t_plane_sf plane);

# endif
#endif
