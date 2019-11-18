/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radius.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:03:12 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:03:13 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RADIUS_H
# define RADIUS_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "sphere_types.h"
#  include "sphere_types_internal.h"
#  include "vector_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "sphere_types.h"
#  include "vector_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
radius(const t_sphere_sf s);
t_v3df __attribute__((CONST,CLONE,ARCH))
radius(const t_sphere_df s);
t_v3sf __attribute__((PURE,CLONE,ARCH))
radius(const struct s_sphere_sf *const restrict s);
t_v3df __attribute__((PURE,CLONE,ARCH))
radius(const struct s_sphere_df *const restrict s);

# endif
#endif
