/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_condition.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:04:30 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:04:32 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "record_condition.h"
#endif

_Bool __attribute__((CONST,CLONE,ARCH))
	condition(register const t_record_sf record)
{
	return (!!(((t_record_mask_qi)record)[0]));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
