/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:57:25 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:57:27 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_RAY_H
# define CAMERA_RAY_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "random_float.h"
#  if defined(__APPLE__)
#   include <stdlib.h>
#  else
#   include <malloc.h>
#  endif
#  include "camera_types_internal.h"
#  include "vector_types.h"
#  include "ray_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "camera_types.h"
#  include "vector_types.h"
#  include "ray_types.h"

t_ray_sf __attribute__((CLONE,CONST,ARCH))
ray(struct s_camera_sf *const restrict camera,
	register const t_v3sf u,
	register const t_v3sf v);

t_ray_sf __attribute__((CLONE,CONST,ARCH))
ray(struct s_advanced_camera_sf *const restrict camera,
	register const float s,
	register const float t);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
