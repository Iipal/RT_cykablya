/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:48:50 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:48:51 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "cross.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	cross(register const t_v2sf x, register const t_v2sf y)
{
	return ((t_v3sf){ 0.0f, 0.0f, x.x * y.y - x.y * y.x });
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	cross(register const t_v2df x, register const t_v2df y)
{
	return ((t_v3df){ 0.0, 0.0, x.x * y.y - x.y * y.x });
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
