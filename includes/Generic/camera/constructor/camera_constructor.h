/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_constructor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:59:38 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:59:40 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_CONSTRUCTOR_H
# define CAMERA_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "global_definitions.h"
#  include "vector.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
#  include "camera_types_internal.h"
#  include "lower_left_corner.h"
#  include "horizontal.h"
#  include "vertical.h"
#  include "camera_origin.h"
# endif

# ifdef DECLARATION
#  include "camera_types.h"

struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
*camera(void);
struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
*camera(register const float fov, register const float aspect_ratio);
struct s_camera_sf __attribute__((ARCH,CLONE,ALIGN))
*camera(register const t_v3sf look_from,
		register const t_v3sf look_at,
		register const t_v3sf position,
		register const t_v2sf params);
struct s_advanced_camera_sf __attribute__((ARCH,CLONE,ALIGN))
*camera(register const t_v3sf look_from,
		register const t_v3sf look_at,
		register const t_v3sf position,
		register const t_v4sf params);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
