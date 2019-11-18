/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scatter.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 03:37:40 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 03:37:41 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCATTER_H
# define SCATTER_H

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
#  include "color.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include <stddef.h>
#  include <stdbool.h>
#  include "vector_types.h"
#  include "ray_types.h"
#  include "hitable_types.h"

t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
scatter_labmbertian(register const union u_hitables *restrict hitables,
					register const t_record_sf record,
					register const t_v3sf attenuation,
					register const size_t depth);
t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
scatter_metal(register const union u_hitables *restrict hitables,
			register const t_record_sf record,
			register const t_ray_sf r,
			register const size_t depth);
t_v3sf __attribute__((CONST,SMALL_STACK,ARCH))
scatter_dielectric(register const union u_hitables *restrict hitables,
					register const t_record_sf record,
					register const t_ray_sf r,
					register const size_t depth);

# endif
#endif
