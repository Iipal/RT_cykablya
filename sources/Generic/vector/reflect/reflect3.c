/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:54:05 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:54:06 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "reflect.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reflect(register const t_v3sf x, register const t_v3sf n)
{
	return (x - 2.0f * vec_dot(x, n) * n);
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	reflect(register const t_v3df x, register const t_v3df n)
{
	return (x - 2.0 * vec_dot(x, n) * n);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
