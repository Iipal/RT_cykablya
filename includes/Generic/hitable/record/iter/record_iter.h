/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_iter.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 23:02:05 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/16 23:02:06 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RECORD_ITER_H
# define RECORD_ITER_H

# ifdef IMPLEMETNATION
#  include <stddef.h>
#  include "attributes.h"
#  include "record_types_internal.h"
# endif

# ifdef DECLARATION
#  include <stddef.h>
#  include "attributes.h"
#  include "record_types.h"

size_t __attribute__((CONST,CLONE,ARCH))
iter(register const t_record_sf record);

# endif
#endif
