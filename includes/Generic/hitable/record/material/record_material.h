/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_material.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:11:52 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:11:53 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_MATERIAL_H
# define RECORD_MATERIAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "material.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "material.h"
#  include "record_types.h"

enum e_material __attribute__((CONST,CLONE,ARCH))
material(register const t_record_sf record);

# endif
#endif
