/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:48:12 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:48:14 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vector_constructor.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec(register const float e_0, register const float e_1)
{
	return ((const t_v2sf){ e_0, e_1 });
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec(register const double e_0, register const double e_1)
{
	return ((const t_v2df){ e_0, e_1 });
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
