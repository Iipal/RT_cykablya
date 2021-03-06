/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_normal.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:16:12 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:16:13 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_NORMAL_H
# define RECORD_NORMAL_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "vector.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "record_types.h"
#  include "vector_types.h"

t_v3sf __attribute__((CONST,CLONE,ARCH))
normal(register const t_record_sf record);
t_v3df __attribute__((CONST,CLONE,ARCH))
normal(register const t_record_df record);

# endif
#endif
