/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract_reflect2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:56:06 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:56:07 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "refract_reflect.h"
#endif

t_v2sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_reflect(register const t_v2sf x,
					register const t_v2sf n,
					register const float e,
					register const t_v2sf reflect)
{
	register const float	k = 1.0f - e * e * (1.0f - dot(x, n) * dot(x, n));

	return (k >= 0.0f) ? e * x - (e * dot(x, n) + sqroot(k)) * n : reflect;
}

t_v2df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract_reflect(register const t_v2df x,
					register const t_v2df n,
					register const double e,
					register const t_v2df reflect)
{
	register const double	k = 1.0 - e * e * (1.0 - dot(x, n) * dot(x, n));

	return (k >= 0.0f) ? e * x - (e * dot(x, n) + sqroot(k)) * n : reflect;
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
