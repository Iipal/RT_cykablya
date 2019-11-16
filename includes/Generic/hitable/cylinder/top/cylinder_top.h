/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_top.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:24:07 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:24:08 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CYLINDER_TOP_H
# define CYLINDER_TOP_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "vector.h"
#  include "cylinder_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
top(register const t_cylinder_sf cylinder);

# endif
#endif
