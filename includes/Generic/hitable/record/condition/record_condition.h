/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_condition.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:10:46 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:10:47 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_CONDITION_H
# define RECORD_CONDITION_H

# ifdef IMPLEMETNATION
#  include "attributes.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include "attributes.h"
#  include "record_types.h"

_Bool __attribute__((CONST,CLONE,ARCH))
condition(register const t_record_sf record);

# endif
#endif
