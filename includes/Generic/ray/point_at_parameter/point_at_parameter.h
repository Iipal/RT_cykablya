/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_at_parameter.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:37:36 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:37:37 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_AT_PARAMETER_H
# define POINT_AT_PARAMETER_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "ray_types_internal.h"
#  include "vector_types.h"
#  include "origin.h"
#  include "direction.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "ray_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
point_at_parameter(register const struct s_ray_sf *const restrict r,
					register const float t);
t_v3sf __attribute__((CONST,CLONE,ARCH))
point_at_parameter(register const struct s_ray_sf *const restrict r,
					register const t_v3sf t);
t_v3sf __attribute__((CONST,CLONE,ARCH))
point_at_parameter(register const t_ray_sf r, register const float t);
t_v3sf __attribute__((CONST,CLONE,ARCH))
point_at_parameter(register const t_ray_sf r, register const t_v3sf t);
t_v3df __attribute__((CONST,CLONE,ARCH))
point_at_parameter(register const struct s_ray_df *const restrict r,
					register const double t);
t_v3df __attribute__((CONST,CLONE,ARCH))
point_at_parameter(register const struct s_ray_df *const restrict r,
					register const t_v3df t);
t_v3df __attribute__((CONST,CLONE,ARCH))
point_at_parameter(const t_ray_df r,
					register const double t);
t_v3df __attribute__((CONST,CLONE,ARCH))
point_at_parameter(const t_ray_df r,
					register const t_v3df t);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
