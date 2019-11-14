/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot4.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:49:19 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:49:20 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "dot.h"
#endif

float __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	dot(register const t_v4sf x, register const t_v4sf y)
{
	return (reduce_add(x * y));
}

double __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	dot(register const t_v4df x, register const t_v4df y)
{
	return (reduce_add(x * y));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
