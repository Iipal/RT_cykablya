/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_planes.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:01:03 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:01:04 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAHEDRON_PLANES_H
# define TETRAHEDRON_PLANES_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "tetrahedron_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_a(register const t_tetrahedron_sf tetrahedron);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_b(register const t_tetrahedron_sf tetrahedron);
t_v3sf __attribute__((CONST,CLONE,ARCH))
plane_c(register const t_tetrahedron_sf tetrahedron);

# endif
#endif
