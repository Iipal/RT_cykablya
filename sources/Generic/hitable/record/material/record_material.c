/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   record_material.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshevchu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 04:05:26 by sshevchu          #+#    #+#             */
/*   Updated: 2019/11/17 04:05:27 by sshevchu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "record_material.h"
#endif

enum e_material __attribute__((CONST,CLONE,ARCH))
	material(register const t_record_sf record)
{
	return ((const enum e_material)(((t_record_mask_qi)record)[1]));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
