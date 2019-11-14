/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract_do2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:55:30 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:55:31 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "refract_do.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_do(register const t_v2sf x,
				register const t_v2sf n,
				register const float e,
				register const float k)
{
	return (e * x - (e * dot(x, n) + sqroot(k)) * n);
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_do(register const t_v2df x,
				register const t_v2df n,
				register const double e,
				register const double k)
{
	return (e * x - (e * dot(x, n) + sqroot(k)) * n);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
