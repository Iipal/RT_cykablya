/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdatskov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:13:05 by sdatskov          #+#    #+#             */
/*   Updated: 2019/11/14 21:13:06 by sdatskov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(IMPLEMETNATION) && !defined(DECLARATION)
# define IMPLEMETNATION
# define DECLARATION
# include "horizontal.h"
# define TLS_VEC _Thread_local t_v3sf
#endif

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(void)
{
	static TLS_VEC	coord = { 4.0f, 0.0f, 0.0f };

	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(register const float half_width)
{
	static TLS_VEC	coord;

	coord = vec(2.0f * half_width, 0.0f, 0.0f);
	return (&coord);
}

t_v3sf __attribute__((ARCH,CLONE,ALIGN,SMALL_STACK))
	*horizontal(register const t_v3sf vec)
{
	static TLS_VEC	coord;

	coord = vec;
	return (&coord);
}

#if defined(IMPLEMETNATION) && defined(DECLARATION)
# undef IMPLEMETNATION
# undef DECLARATION
#endif
