/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_constructor.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:18:22 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:18:24 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIAL_CONSTRUCTOR_H
# define MATERIAL_CONSTRUCTOR_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "material_types.h"
#  include "vector_types.h"

t_material_sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
material(register const enum e_material current_material,
		register const t_v3sf albedo);
t_material_sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
material(register const enum e_material current_material,
		register const t_v3sf albedo,
		register const float fuzz);
t_material_sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
material(register const enum e_material current_material,
		register const float ri);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
