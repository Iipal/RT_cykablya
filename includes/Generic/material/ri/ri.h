/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ri.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:19:21 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:19:22 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RI_H
# define RI_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "material_types.h"
#  include "vector_types.h"

float __attribute__((CONST,CLONE,ARCH))
ri(register const t_material_sf material);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
