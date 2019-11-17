/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_normal.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:05:38 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:05:40 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "record_normal.h"
#endif

t_v3sf __attribute__((CONST,CLONE,ARCH))
	normal(register const t_record_sf record)
{
	return (vec(record[5], record[6], record[7]));
}

t_v3df __attribute__((CONST,CLONE,ARCH))
	normal(register const t_record_df record)
{
	return (vec(record[5], record[6], record[7]));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
