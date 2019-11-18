/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshepele <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:48:19 by dshepele          #+#    #+#             */
/*   Updated: 2019/11/14 20:48:20 by dshepele         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vector_constructor.h"
#endif

t_v3sf __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec(register const float e_0,
		register const float e_1,
		register const float e_2)
{
	return ((const t_v3sf){ e_0, e_1, e_2 });
}

t_v3df __attribute__((CONST,CLONE,SMALL_STACK,ARCH))
	vec(register const double e_0,
		register const double e_1,
		register const double e_2)
{
	return ((const t_v3df){ e_0, e_1, e_2 });
}

t_v3sf __attribute__((PURE,CLONE,SMALL_STACK,ARCH))
	vec(const float e[static 3])
{
	return ((const t_v3sf)((const t_v3sf_a){ *((const t_v3sf_a*)e) }));
}

t_v3df __attribute__((PURE,CLONE,SMALL_STACK,ARCH))
	vec(const double e[static 3])
{
	return ((const t_v3df)((const t_v3df_a){ *((const t_v3df_a*)e) }));
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
