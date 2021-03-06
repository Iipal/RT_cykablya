/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:37:01 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:37:02 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIRECTION_H
# define DIRECTION_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "ray_types_internal.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "ray_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
direction(register const t_ray_sf r);
t_v3df __attribute__((CONST,CLONE,ARCH))
direction(const t_ray_df r);
t_v3sf __attribute__((PURE,CLONE,ARCH))
direction(const struct s_ray_sf *const restrict r);
t_v3df __attribute__((PURE,CLONE,ARCH))
direction(const struct s_ray_df *const restrict r);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
