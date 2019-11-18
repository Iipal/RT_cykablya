/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:54:34 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:54:35 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "refract.h"
#endif

t_v4sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract(register const t_v4sf x,
			register const t_v4sf n,
			register const float eta)
{
	register const float	dot_xn = dot(x, n);
	register const float	k = 1.0f - eta * eta * (1.0f - dot_xn * dot_xn);

	return ((k >= 0.0f) ? eta * x - (eta * dot_xn + sqroot(k) * n) : 0.0f);
}

t_v4df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	refract(register const t_v4df x,
			register const t_v4df n,
			register const double eta)
{
	register const double	dot_xn = dot(x, n);
	register const double	k = 1.0f - eta * eta * (1.0f - dot_xn * dot_xn);

	return ((k >= 0.0f) ? eta * x - (eta * dot_xn + sqroot(k) * n) : 0.0f);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
