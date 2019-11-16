/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:08:18 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:08:19 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include <stddef.h>
#  include <stdbool.h>
#  include "hit.h"
#  include "record_types.h"
#  include "record_types_internal.h"
#  include "random_float.h"
#  include "vector.h"
#  include "material.h"
#  include "vector_int_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include <stddef.h>
#  include <stdbool.h>
#  include "vector_types.h"
#  include "ray_types.h"
#  include "hitable_types.h"

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
color(register const t_ray_sf ray,
	register const union u_hitables *restrict hitables);
t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
color(register const t_ray_sf r,
	register const union u_hitables *restrict hitables,
	register const size_t depth);

# endif
#endif
