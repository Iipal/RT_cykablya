/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:17:16 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:17:18 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "vertical.h"
# define TLS_VEC _Thread_local t_v3sf
#endif

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(void)
{
	static TLS_VEC	coord = { 0.0f, 2.0f, 0.0f };

	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(register const float half_height)
{
	static TLS_VEC	coord;

	coord = vec(0.0f, 2.0f * half_height, 0.0f);
	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*vertical(register const t_v3sf vec)
{
	static TLS_VEC	coord;

	coord = vec;
	return (&coord);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
