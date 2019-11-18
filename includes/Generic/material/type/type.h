/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:22:11 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 22:22:12 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_H
# define TYPE_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector_types.h"
#  include "material_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "material_types.h"
#  include "vector_types.h"

enum e_material __attribute__((CONST,CLONE,ARCH))
type(register const t_material_sf material);

#  ifndef IMPLEMETNATION
#  endif
# endif
#endif
