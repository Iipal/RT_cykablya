/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_constructor.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:19:20 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:19:21 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLANE_CONSTRUCTOR_H
# define PLANE_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "plane_types.h"

t_plane_sf __attribute__((CONST,CLONE,ARCH))
plane(register const t_v3sf a,
		register const t_v3sf b,
		register const t_v3sf c,
		register const t_v3sf d);

# endif
#endif
