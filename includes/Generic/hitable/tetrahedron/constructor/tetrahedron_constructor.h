/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetrahedron_constructor.h                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:04:40 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:04:41 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TETRAHEDRON_CONSTRUCTOR_H
# define TETRAHEDRON_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "tetrahedron_types.h"
#  include "vector.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "tetrahedron_types.h"
#  include "vector.h"

t_tetrahedron_sf __attribute__((CONST,CLONE,ARCH))
tetrahedron(register const t_v3sf a,
			register const t_v3sf b,
			register const t_v3sf c);

# endif
#endif
